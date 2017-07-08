#pragma once

#ifndef LI_H
#define LI_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Li: public HtmlElement{
		public:
			Li();
			~Li();

			std::string ToString() override;
			std::string GetTypeString() override;

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
#endif