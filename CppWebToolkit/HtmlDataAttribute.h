#pragma once
#include "DNC\String.h"

namespace dnc{
	namespace Web{
		class HtmlDataAttribute: public Object{
		public:
			HtmlDataAttribute();
			HtmlDataAttribute(String& name, String& value);
			~HtmlDataAttribute();

			std::string toString();
			std::string getTypeString();

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