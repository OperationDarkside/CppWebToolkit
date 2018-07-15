#pragma once
#ifndef WEBAPPLICATION_H
#define WEBAPPLICATION_H

#include "ThreadPool.h"
#include "BlockingQueue.h"
#include "PageHolder.h"
#include "WebPage.h"
#include "SessionProviderBase.h"
#include "DNC\String.h"
#include "DNC\Socket.h"
#include "DNC\Console.h"

#include <vector>
#include <list>
#include <unordered_map>
#include <memory>
#include <utility>

namespace dnc {
	namespace Web {
		template<
			typename Session,
			typename SessionProvider,
			typename = std::enable_if_t<
				std::is_base_of<SessionProviderBase<Session>, SessionProvider>::value &&
				std::is_base_of<SessionBase, Session>::value,
				SessionProvider>
			>
		class WebApplication : public Object {
		public:
			WebApplication () {};
			~WebApplication () {};

			std::string ToString () override {
				return std::string ("System.Web.WebApplication");
			};
			std::string GetTypeString () override {
				return std::string ("WebApplication");
			};

			template<typename T, typename = std::enable_if_t<std::is_base_of<WebPage<Session>, T>::value, T>>
			void registerPage(String& name) {

				std::unique_ptr<PageHolder<T, Session>> ptr = std::make_unique<PageHolder<T, Session>>();

				pages.emplace(name.GetStringValue(), std::move(ptr));
			}

			void Start () {
				bool is_running = true;
				int select_ret_val = 0;
				Net::Sockets::Socket listenSock (Net::AddressFamily::IPv4, Net::Sockets::SocketType::Stream, Net::Sockets::ProtocolType::Tcp);
				//std::vector<unsigned char> addr;
				std::list<Net::Sockets::Socket> clientSockets;
				std::vector<Net::Sockets::Socket*> readSockets;
				std::vector<Net::Sockets::Socket*> writeSockets;
				std::vector<Net::Sockets::Socket*> errorSockets;

				SetupPages ();

				listenSock.Bind (Net::IPEndPoint (Net::IPAddress ({127,0,0,1}), 999));
				listenSock.Listen (10);

				while (is_running) {

					readSockets.push_back (&listenSock);
					for (Net::Sockets::Socket& s : clientSockets) {
						readSockets.push_back (&s);
					}

					select_ret_val = Net::Sockets::Socket::Select (readSockets, writeSockets, errorSockets, 0, 0);

					switch (select_ret_val) {
					case 0: // Time limit expired
						break;
					case SOCKET_ERROR:
					{
						int error = WSAGetLastError ();
						Console::WriteLine (error);
						break;
					}
					break;
					default: // SUCCESS
						if (std::find (readSockets.begin (), readSockets.end (), &listenSock) != readSockets.end ()) {
							// New incoming client
							Net::Sockets::Socket accSock = listenSock.Accept ();
							clientSockets.push_back (accSock);

						} else {
							// Something to read
							try {
								HandleReads (clientSockets, readSockets);
							} catch (std::exception& ex) {
								const char * msg = ex.what ();
								Console::WriteLine (msg);
							}
						}
						break;
					}
					readSockets.clear ();
				}
			};

		private:
			std::unordered_map<std::string, std::unique_ptr<PageHolderBase<Session>>> pages;
			std::vector<std::thread> threads;
			BlockingQueue<HttpRequest<Session>> queue;

			SessionProvider session_provider;

			void SetupPages () {
				size_t supported_thread_num = std::thread::hardware_concurrency ();

				for (int i = 0; i < supported_thread_num; ++i) {
					threads.push_back (std::move (std::thread ([&] () {
						while (true) {
							HttpRequest<Session> request = queue.Pop ();

							try {
								//HttpResponse response = wp->HandleRequest (request);
								PageHolderBase<Session>* page = request.Page ();
								if (page == nullptr) {
									continue;
								}

								std::optional<std::string> session_cookie = request.HeaderField ("Cookie");
								if(session_cookie.has_value()){
									std::string& cookie_value = session_cookie.value ();

									size_t equals_pos = cookie_value.find ("id=");
									if (equals_pos != std::string::npos) {
										std::string session_id = cookie_value.substr (equals_pos + 3);
										std::optional<Session*> session = session_provider.GetSession (session_id);
										if (session.has_value ()) {
											request.CurrentSession (session.value ());
										}
									}
								}
								
								HttpResponse<Session> response = page->GetResponse (std::move (request));

								auto& fields = response.HeaderFields ();
								fields["Connection"] = " close";
								fields["Content-Type"] = " text/html";
								if (response.HasSession ()) {
									const std::string& new_session_id = session_provider.CreateSession (response.MoveSession ());
									fields["Set-Cookie"] = "id=" + new_session_id;
								}

								// response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

								Net::Sockets::Socket& socket = request.Socket ();

								std::string resp_str = response.toSendString ();

								socket.Send (resp_str.c_str ());
								socket.Disconnect ();
							} catch (std::exception& ex) {
								const char* what = ex.what ();
							}
							// socket->Disconnect();
						}
					})));
				}
			};
			void HandleReads (std::list<Net::Sockets::Socket>& clientSockets, std::vector<Net::Sockets::Socket*>& readSockets) {
				std::vector<Net::Sockets::Socket*> eraseSockets;

				for (Net::Sockets::Socket* s : readSockets) {
					String request_str;
					while (true) {
						std::array<char, 100> recvBuffer;

						int bytesrecvd = s->Receive (recvBuffer);

						if (bytesrecvd < 1) {
							switch (bytesrecvd) {
							case 0:
								Console::WriteLine ("Active Client Disconnect");
								// ERASE AFTER DISCONNECT
								eraseSockets.push_back (s);
								break;
							case SOCKET_ERROR:
								Console::WriteLine ("SOCKET_ERROR in Receive");
								break;
							}
							break;
						}

						String recvBufferStr = recvBuffer;

						request_str += recvBufferStr;

						if (bytesrecvd != 100) {
							break;
						}
					}

					if (request_str[0] == 0) {
						Console::WriteLine ("Nothing received");
						continue;
					}

					// Parse HTTP Header
					HttpRequest<Session> request;
					request.Parse (request_str.GetStringValue ());
					request.Socket (*s);

					auto& page = pages.find (request.Resource ());
					if (page == pages.end ()) {
						s->Send ("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
						s->Disconnect ();
						eraseSockets.push_back (s);
						// ERASE AFTER DISCONNECT
						Console::WriteLine (dnc::String ("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n" + request.Resource ()));
						continue;
					}

					PageHolderBase<Session>* holder = page->second.get ();
					request.Page (holder);



					queue.Push (std::move (request));
					//holder->GetResponse (std::move (request));
					//response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

					//Console::WriteLine(response);

					//s->Send(response.GetStringValue().c_str());
					//s->Disconnect();
					// ERASE AFTER DISCONNECT
					eraseSockets.push_back (s);
				}
				for (Net::Sockets::Socket* s : eraseSockets) {
					clientSockets.erase (std::remove (clientSockets.begin (), clientSockets.end (), *s), clientSockets.end ());
					//readSockets.erase(std::remove(readSockets.begin(), readSockets.end(), s), readSockets.end());
				}
			};
		};
	}
}

#endif // !WEBAPPLICATION_H