#pragma once

#ifndef TBODY_H
#define TBODY_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Tbody : public HtmlElement {
		public:
			Tbody();
			~Tbody();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif