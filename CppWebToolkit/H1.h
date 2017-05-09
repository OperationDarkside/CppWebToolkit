#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class H1: public HtmlElement{
		public:
			H1();
			~H1();
			String toHtml();

			void setText(String* _txt);
		protected:
			String txt;
		};
	}
}