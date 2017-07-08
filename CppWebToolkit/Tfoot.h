#pragma once

#ifndef TFOOT_H
#define TFOOT_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Tfoot : public HtmlElement {
		public:
			Tfoot();
			~Tfoot();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif