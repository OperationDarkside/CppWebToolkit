#pragma once

#ifndef TR_H
#define TR_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Tr : public HtmlElement {
		public:
			Tr();
			~Tr();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif