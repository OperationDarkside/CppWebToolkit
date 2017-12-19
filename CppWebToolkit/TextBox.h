#pragma once

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Widget.h"
#include "Input.h"

namespace dnc {
	namespace Web {
		class TextBox : public Widget {
		public:
			TextBox();
			~TextBox();

			std::string ToString() override;
			std::string GetTypeString() override;

			String& Text();
			void Text(String& txt);

			virtual String toHtml() override;
			virtual void toHtml(StringBuilder& sb) override;
		private:
			Input in;
		};
	}
}
#endif // !TEXTBOX_H