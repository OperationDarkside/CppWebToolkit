#include "WebApplication.h"
#include "DNC\Console.h"
#include "HttpHeader.h"
#include <chrono>
#include <thread>
#include <algorithm>

namespace dnc {
	namespace Web {

		WebApplication::WebApplication() {}


		WebApplication::~WebApplication() {}

		std::string WebApplication::ToString() {
			return std::string("System.Web.WebApplication");
		}

		std::string WebApplication::GetTypeString() {
			return std::string("WebApplication");
		}

		void WebApplication::Start() {
			bool is_running = true;
			int select_ret_val = 0;
			Net::Sockets::Socket listenSock(Net::AddressFamily::IPv4, Net::Sockets::SocketType::Stream, Net::Sockets::ProtocolType::Tcp);
			//std::vector<unsigned char> addr;
			std::list<Net::Sockets::Socket> clientSockets;
			std::vector<Net::Sockets::Socket*> readSockets;
			std::vector<Net::Sockets::Socket*> writeSockets;
			std::vector<Net::Sockets::Socket*> errorSockets;
			//std::vector<Net::Sockets::Socket*> removeSockets;
			/*
			addr.push_back(127);
			addr.push_back(0);
			addr.push_back(0);
			addr.push_back(1);
			*/
			listenSock.Bind(Net::IPEndPoint(Net::IPAddress({ 127,0,0,1 }), 999));
			listenSock.Listen(10);

			while (is_running) {
				/*for (Net::Sockets::Socket& s : clientSockets) {
					if (!s.Connected()) {
						removeSockets.push_back(&s);
					}
				}

				for (Net::Sockets::Socket* s : removeSockets) {
					clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), *s), clientSockets.end());
				}
				removeSockets.clear();*/

				readSockets.push_back(&listenSock);
				for (Net::Sockets::Socket& s : clientSockets) {
					readSockets.push_back(&s);
				}

				select_ret_val = Net::Sockets::Socket::Select(readSockets, writeSockets, errorSockets, 0, 0);

				switch (select_ret_val) {
				case 0: // Time limit expired
					break;
				case SOCKET_ERROR:
				{
					int error = WSAGetLastError();
					Console::WriteLine(error);
					break;
				}
				break;
				default: // SUCCESS
					if (std::find(readSockets.begin(), readSockets.end(), &listenSock) != readSockets.end()) {
						// New incoming client
						Net::Sockets::Socket accSock = listenSock.Accept();
						clientSockets.push_back(accSock);
						/*
						if(readSockets.size() > 1) {
							// remove listening socket
							readSockets.erase(std::remove(readSockets.begin(), readSockets.end(), &listenSock), readSockets.end());
							// Something to read
							HandleReads(clientSockets, readSockets);
						}
						*/
					}
					else {
						// Something to read
						HandleReads(clientSockets, readSockets);
					}
					break;
				}
				readSockets.clear();
			}
			/*
			while(true) {
				String request;

				Net::Sockets::Socket accSock = listenSock.Accept();
				accSock.Blocking(false);

				std::this_thread::sleep_for(std::chrono::milliseconds(2));

				std::chrono::time_point<std::chrono::high_resolution_clock> t_construct = std::chrono::high_resolution_clock::now();
				try {
					int receive_num = 0;
					while(true) {
						std::array<char, 100> recvBuffer;

						int bytesrecvd = accSock.Receive(recvBuffer);

						if(bytesrecvd < 1 && receive_num == 0) {
							break;
						}

						String recvBufferStr = recvBuffer;

						request += recvBufferStr;

						if(bytesrecvd != 100) {
							break;
						}

						++receive_num;
					}
					if(request[0] == 0) {
						Console::WriteLine("Unnecessary connection");
						//accSock.Disconnect();
						continue;
					}

					Console::WriteLine(request);
					Console::WriteLine();

					String firstLine = request.Substring(0, request.IndexOf('\n'));
					dnc::Collections::Generic::List<String> firstLineValues = firstLine.Split(' ');
					String path = firstLineValues[1];

					auto& page = pages.find(path.GetStringValue());
					if(page == pages.end()) {
						accSock.Send("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
						accSock.Disconnect();
						Console::WriteLine("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
						continue;
					}

					PageHolderBase* holder = page->second.get();

					String response = holder->getResponse(request);
					response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

					Console::WriteLine(response);

					accSock.Send(response.GetStringValue().c_str());
					accSock.Disconnect();
					// accSock.Close();
				} catch(std::exception& ex) {
					ex.what();
				}
				std::chrono::time_point<std::chrono::high_resolution_clock> t_render = std::chrono::high_resolution_clock::now();
				std::chrono::microseconds diff = std::chrono::duration_cast<std::chrono::microseconds>(t_render - t_construct);
				Console::WriteLine((int) diff.count());
			}
			*/
		}

		void WebApplication::HandleReads(std::list<Net::Sockets::Socket>& clientSockets, std::vector<Net::Sockets::Socket*>& readSockets) {
			std::vector<Net::Sockets::Socket*> eraseSockets;

			for (Net::Sockets::Socket* s : readSockets) {
				String request;
				while (true) {
					std::array<char, 100> recvBuffer;

					int bytesrecvd = s->Receive(recvBuffer);

					if (bytesrecvd < 1) {
						switch (bytesrecvd) {
						case 0:
							Console::WriteLine("Active Client Disconnect");
							// ERASE AFTER DISCONNECT
							eraseSockets.push_back(s);
							break;
						case SOCKET_ERROR:
							Console::WriteLine("SOCKET_ERROR in Receive");
							break;
						}
						break;
					}

					String recvBufferStr = recvBuffer;

					request += recvBufferStr;

					if (bytesrecvd != 100) {
						break;
					}
				}

				if (request[0] == 0) {
					Console::WriteLine("Nothing received");
					continue;
				}

				// Parse HTTP Header
				HttpHeader header;
				header.Parse(request);
				header.Socket(*s);

				auto& page = pages.find(header.Path().GetStringValue());
				if (page == pages.end()) {
					s->Send("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
					s->Disconnect();
					eraseSockets.push_back(s);
					// ERASE AFTER DISCONNECT
					Console::WriteLine("HTTP/1.1 404 Not Found\r\nConnection: close\r\n\r\n");
					continue;
				}

				PageHolderBase* holder = page->second.get();

				holder->GetResponse(std::move(header));
				//response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

				//Console::WriteLine(response);

				//s->Send(response.GetStringValue().c_str());
				//s->Disconnect();
				// ERASE AFTER DISCONNECT
				eraseSockets.push_back(s);
			}
			for (Net::Sockets::Socket* s : eraseSockets) {
				clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), *s), clientSockets.end());
				//readSockets.erase(std::remove(readSockets.begin(), readSockets.end(), s), readSockets.end());
			}
		}


	}
}