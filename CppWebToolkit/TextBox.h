#pragma once

#ifndef TEXTBOX_H

#include "Widget.h"
#include "Input.h"

namespace dnc {
	namespace Web {
		class TextBox : public Widget {
		public:
			TextBox();
			~TextBox();

			void SetText(String& txt);

			virtual String toHtml() override;
		private:
			Input in;
			//String str;
		};
	}
}
#endif // !TEXTBOX_H