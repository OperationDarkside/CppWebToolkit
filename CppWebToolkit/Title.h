#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Title: public HtmlElement{
		public:
			Title();
			~Title();

			std::string ToString();
			std::string getTypeString();

			String toHtml() override;

			void SetText(String value);

		private:
			String text;
		};
	}
}