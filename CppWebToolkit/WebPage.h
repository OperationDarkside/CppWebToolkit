#pragma once
#ifndef WEBPAGE_H
#define WEBPAGE_H

#include "DNC\String.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "SessionBase.h"

#include <optional>

namespace dnc {
	namespace Web {
		template<typename Session, typename = std::enable_if_t<std::is_base_of<SessionBase, Session>::value, Session>>
		class WebPage : public Object {
		public:
			//WebPage();
			//~WebPage();

			std::string ToString () override {
				return std::string ("System.Web.WebPage");
			};
			std::string GetTypeString () override {
				return std::string ("WebPage");
			};

			virtual HttpResponse<Session> HandleRequest(HttpRequest<Session>& request) = 0;
		};
	}
}

#endif // !WEBPAGE_H