#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Div: public HtmlElement{
		public:
			Div();
			~Div();

			std::string ToString();
			std::string getTypeString();

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}