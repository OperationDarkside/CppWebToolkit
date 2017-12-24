#pragma once
#ifndef WEBPAGE_H
#define WEBPAGE_H

#include "DNC\String.h"

namespace dnc {
	namespace Web {
		class WebPage : public Object {
		public:
			WebPage();
			~WebPage();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String HandleRequest(String& request) = 0;
		};
	}
}

#endif // !WEBPAGE_H