#pragma once
#ifndef PAGEHOLDERBASE_H
#define PAGEHOLDERBASE_H

#include "DNC\String.h"
#include "DNC\Socket.h"
#include "HttpHeader.h"

namespace dnc {
	namespace Web {
		class PageHolderBase : public Object {
		public:
			PageHolderBase();
			~PageHolderBase();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual void GetResponse(HttpHeader&& request) = 0;
		};
	}
}
#endif // !PAGEHOLDERBASE_H