#pragma once
#ifndef PAGEHOLDERBASE_H
#define PAGEHOLDERBASE_H

#include "DNC\String.h"
#include "DNC\Socket.h"
// #include "HttpRequest.h"
#include "HttpResponse.h"

namespace dnc {
	namespace Web {
		class HttpRequest;

		class PageHolderBase : public Object {
		public:
			PageHolderBase();
			~PageHolderBase();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual HttpResponse GetResponse(HttpRequest&& request) = 0;
		};
	}
}
#endif // !PAGEHOLDERBASE_H