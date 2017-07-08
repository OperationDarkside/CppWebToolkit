#pragma once

#ifndef BODY_H
#define BODY_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Body: public HtmlElement{
		public:
			Body();
			~Body();

			std::string ToString() override;
			std::string GetTypeString() override;
		};

	}
}
#endif