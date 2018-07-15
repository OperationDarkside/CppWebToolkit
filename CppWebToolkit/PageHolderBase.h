#pragma once
#ifndef PAGEHOLDERBASE_H
#define PAGEHOLDERBASE_H

#include "DNC\String.h"
#include "DNC\Socket.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "SessionProviderBase.h"

#include <optional>

namespace dnc {
	namespace Web {
		
		template<typename Session, typename = std::enable_if_t<std::is_base_of<SessionBase, Session>::value, Session>>
		class PageHolderBase : public Object {
		public:
			//template<typename Session, typename = std::enable_if_t<std::is_base_of<SessionBase, Session>::value, Session>>
			//class HttpRequest;

			PageHolderBase () {};
			~PageHolderBase() {};

			std::string ToString() override {
				return std::string ("System.Web.PageHolderBase");
			};
			std::string GetTypeString() override {
				return std::string ("PageHolderBase");
			};

			virtual HttpResponse<Session> GetResponse(HttpRequest<Session>&& request) = 0;
		};
	}
}
#endif // !PAGEHOLDERBASE_H