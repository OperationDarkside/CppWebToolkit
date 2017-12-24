#include "WebApplication.h"
#include "DNC\Socket.h"
#include "DNC\Console.h"
#include <chrono>

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
			Net::Sockets::Socket listenSock(Net::AddressFamily::IPv4, Net::Sockets::SocketType::Stream, Net::Sockets::ProtocolType::Tcp);

			std::vector<unsigned char> addr;
			addr.push_back(127);
			addr.push_back(0);
			addr.push_back(0);
			addr.push_back(1);

			listenSock.Bind(Net::IPEndPoint(Net::IPAddress(addr), 999));
			listenSock.Listen(10);

			while(true) {
				String request;

				Net::Sockets::Socket accSock = listenSock.Accept();
				accSock.Blocking(false);

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
						Console::WriteLine("Bla");
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
		}


	}
}