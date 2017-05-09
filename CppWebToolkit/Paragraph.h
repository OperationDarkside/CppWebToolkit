#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{
		class Paragraph: public HtmlElement{
		public:
			Paragraph();
			~Paragraph();

			String toHtml();

			void setText(String* _txt);
		protected:
			String txt;
		};
	}
}