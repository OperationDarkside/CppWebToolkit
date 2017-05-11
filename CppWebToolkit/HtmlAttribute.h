#pragma once
#include "DNC/String.h"

namespace dnc{
	namespace Web{
		class HtmlAttribute: public Object{
		public:
			HtmlAttribute();
			HtmlAttribute(String& name, String& value);
			~HtmlAttribute();

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