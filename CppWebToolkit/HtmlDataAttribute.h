#pragma once

#ifndef HTMLDATAATTRIBUTE_H
#define HTMLDATAATTRIBUTE_H

#include "DNC/String.h"

namespace dnc{
	namespace Web{
		class HtmlDataAttribute: public Object{
		public:
			HtmlDataAttribute();
			HtmlDataAttribute(String& name, String& value);
			~HtmlDataAttribute();

			std::string ToString() override;
			std::string GetTypeString() override;

			String& Name();
			void Name(String& name);

			String& Value();
			void Value(String& value);
		private:
			String name;
			String value;
		};
	}
}
#endif