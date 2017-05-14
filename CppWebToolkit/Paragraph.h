#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{
		class Paragraph: public HtmlElement{
		public:
			Paragraph();
			~Paragraph();

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}