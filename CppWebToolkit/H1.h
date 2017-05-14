#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class H1: public HtmlElement{
		public:
			H1();
			~H1();

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}