#pragma once

#ifndef DIV_H
#define DIV_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Div: public HtmlElement{
		public:
			Div();
			~Div();

			std::string ToString() override;
			std::string GetTypeString() override;

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}
#endif // !DIV_H