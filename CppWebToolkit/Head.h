#pragma once

#ifndef HEAD_H
#define HEAD_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Head: public HtmlElement{
		public:
			Head();
			~Head();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif