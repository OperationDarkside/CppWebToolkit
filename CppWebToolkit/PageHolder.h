#pragma once
#ifndef PAGEHOLDER_H
#define PAGEHOLDER_H

#include "PageHolderBase.h"
#include "WebPage.h"
#include <exception>

namespace dnc {
	namespace Web {
		template<typename Page, typename Session, typename = std::enable_if_t<std::is_base_of<WebPage<Session>, Page>::value, Page>>
		class PageHolder : public PageHolderBase<Session> {
		public:
			PageHolder () {};
			~PageHolder () {};

			std::string ToString () override {
				return std::string ("System.Web.PageHolder");
			};
			std::string GetTypeString () override {
				return std::string ("PageHolder");
			};

			HttpResponse<Session> GetResponse (HttpRequest<Session>&& request) override {
				try {
					HttpResponse<Session> response = page.HandleRequest (request);

					return response;
				} catch (std::exception& ex) {
					const char* what = ex.what ();
					// TODO restart page
					HttpResponse<Session> response;
					response.ResponseCode (RESPONSE_CODE::ERROR_500);
					return response;
				}
			};
		private:
			Page page;
			//std::vector<T> buffered_webpages;
			//ThreadPool threadpool;
			//BlockingQueue<HttpRequest> queue;
		};

		//template<typename Page, typename Session>
		//inline PageHolder<Page, Session>::PageHolder () {
			/*
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
			*/
		//}

		//template<typename Page, typename Session>
		//inline PageHolder<Page, Session>::~PageHolder () {}

		//template<typename Page, typename Session>
		//inline std::string PageHolder<Page, Session>::ToString () {
		//	return std::string ("System.Web.PageHolder");
		//}

		//template<typename Page, typename Session>
		//inline std::string PageHolder<Page, Session>::GetTypeString () {
		//	return std::string ("PageHolder");
		//}

		//template<typename Page, typename Session>
		//inline HttpResponse PageHolder<Page, Session>::GetResponse (HttpRequest<Session>&& request) {
		//	//WebPage* wp = static_cast<WebPage*>(&page);

		//	try {
		//		HttpResponse response = page.HandleRequest (request);

		//		/*auto& fields = response.HeaderFields ();
		//		fields["Connection"] = " close";
		//		fields["Content-Type"] = " text/html";

		//		// response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

		//		Net::Sockets::Socket& socket = request.Socket ();

		//		std::string resp_str = response.toSendString ();

		//		socket.Send (resp_str.c_str ());
		//		socket.Disconnect ();
		//		*/
		//		return response;
		//	} catch (std::exception& ex) {
		//		const char* what = ex.what ();
		//		// TODO restart page
		//		HttpResponse response;
		//		response.ResponseCode (RESPONSE_CODE::ERROR_500);
		//		return response;
		//	}
		//	//queue.Push (std::move (request));
		//	/*T instance;

		//	WebPage* wp = static_cast<WebPage*>(&instance);

		//	String response = wp->HandleRequest(request);

		//	response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n" + response;

		//	Console::WriteLine(response);

		//	s->Send(response.GetStringValue().c_str());
		//	s->Disconnect();*/
		//}
	}
}

#endif // !PAGEHOLDER_H