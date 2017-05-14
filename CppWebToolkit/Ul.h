#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Ul: public HtmlElement{
		public:
			Ul();
			~Ul();

			std::string ToString();
			std::string getTypeString();
		};
	}
}