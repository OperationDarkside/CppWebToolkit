#pragma once
#ifndef PAGEHOLDERBASE_H
#define PAGEHOLDERBASE_H

#include "DNC\String.h"

namespace dnc {
	namespace Web {
		class PageHolderBase : public Object {
		public:
			PageHolderBase();
			~PageHolderBase();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String getResponse(String& request) = 0;
		};
	}
}
#endif // !PAGEHOLDERBASE_H