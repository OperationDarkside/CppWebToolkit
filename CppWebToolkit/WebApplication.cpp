#include "WebApplication.h"
#include "DNC\Console.h"
#include "HttpHeader.h"
#include <chrono>
#include <thread>
#include <algorithm>
#include <exception>

namespace dnc {
	namespace Web {
		/*
		WebApplication::WebApplication () {}


		WebApplication::~WebApplication () {}

		std::string WebApplication::ToString () {
			return std::string ("System.Web.WebApplication");
		}

		std::string WebApplication::GetTypeString () {
			return std::string ("WebApplication");
		}

		void WebApplication::Start () {
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
		}

		void WebApplication::SetupPages () {
			size_t supported_thread_num = std::thread::hardware_concurrency ();

			for (int i = 0; i < supported_thread_num; ++i) {
				threads.push_back (std::move (std::thread ([&] () {
					while (true) {
						auto request = queue.Pop ();

						try {
							//HttpResponse response = wp->HandleRequest (request);
							PageHolderBase* page = request.Page ();
							if (page == nullptr) {
								continue;
							}

							HttpResponse response = page->GetResponse (std::move(request));

							auto& fields = response.HeaderFields ();
							fields["Connection"] = " close";
							fields["Content-Type"] = " text/html";

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
		}

		void WebApplication::HandleReads (std::list<Net::Sockets::Socket>& clientSockets, std::vector<Net::Sockets::Socket*>& readSockets) {
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
				HttpRequest request;
				request.Parse (request_str.GetStringValue ());
				request.Socket (*s);

				auto& page = pages.find (request.Resource ());
				if (page == pages.end ()) {
					s->Send ("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
					s->Disconnect ();
					eraseSockets.push_back (s);
					// ERASE AFTER DISCONNECT
					Console::WriteLine (dnc::String("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n" + request.Resource ()));
					continue;
				}

				PageHolderBase* holder = page->second.get ();
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
		}

		*/
	}
}