#pragma once

#ifndef THEAD_H
#define THEAD_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Thead : public HtmlElement {
		public:
			Thead();
			~Thead();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif