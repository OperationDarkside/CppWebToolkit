#pragma once

#ifndef HTML_H
#define HTML_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Html: public HtmlElement{
		public:
			Html();
			~Html();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif