#pragma once
#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Li: public HtmlElement{
		public:
			Li();
			~Li();

			std::string ToString();
			std::string getTypeString();

			// VALUE
			String Value();
			void Value(String val);

			// TEXT
			void SetText(String txt);

		private:
			String value;

			String getAttributeString() override;
		};
	}
}
