#pragma once
#ifndef PAGEHOLDER_H
#define PAGEHOLDER_H

#include "PageHolderBase.h"
#include "WebPage.h"
#include "ThreadPool.h"
#include "BlockingQueue.h"
#include <exception>

namespace dnc {
	namespace Web {
		template<typename T>
		class PageHolder : public PageHolderBase {
		public:
			PageHolder ();
			~PageHolder ();

			std::string ToString () override;
			std::string GetTypeString () override;

			void GetResponse (HttpRequest&& request) override;
		private:
			std::vector<T> buffered_webpages;
			ThreadPool threadpool;
			BlockingQueue<HttpRequest> queue;
		};

		template<typename T>
		inline PageHolder<T>::PageHolder () {
			size_t supported_thread_num = threadpool.SupportedThreads ();

			buffered_webpages.reserve (supported_thread_num);

			for (int i = 0; i < supported_thread_num; ++i) {
				T instance;

				buffered_webpages.push_back (std::move (instance));
				T& instance_ref = buffered_webpages.back ();

				WebPage* wp = static_cast<WebPage*>(&instance_ref);

				threadpool.Add<WebPage> (wp, [&] (WebPage* wp) {
					while (true) {
						auto request = queue.Pop ();

						try {
							HttpResponse response = wp->HandleRequest (request);

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
				});
			}
		}

		template<typename T>
		inline PageHolder<T>::~PageHolder () {}

		template<typename T>
		inline std::string PageHolder<T>::ToString () {
			return std::string ("System.Web.PageHolder");
		}

		template<typename T>
		inline std::string PageHolder<T>::GetTypeString () {
			return std::string ("PageHolder");
		}

		template<typename T>
		inline void PageHolder<T>::GetResponse (HttpRequest&& request) {
			queue.Push (std::move (request));
			/*T instance;

			WebPage* wp = static_cast<WebPage*>(&instance);

			String response = wp->HandleRequest(request);

			response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

			Console::WriteLine(response);

			s->Send(response.GetStringValue().c_str());
			s->Disconnect();*/
		}
	}
}

#endif // !PAGEHOLDER_H