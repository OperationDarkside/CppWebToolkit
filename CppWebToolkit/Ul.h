#pragma once

#ifndef UL_H
#define UL_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Ul: public HtmlElement{
		public:
			Ul();
			~Ul();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif