#pragma once

#ifndef HTMLATTRIBUTE_H
#define HTMLATTRIBUTE_H

#include "DNC/String.h"

namespace dnc{
	namespace Web{
		class HtmlAttribute: public Object{
		public:
			HtmlAttribute();
			HtmlAttribute(String& name, String& value);
			~HtmlAttribute();

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