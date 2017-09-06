#include "TextBox.h"

namespace dnc {
	namespace Web {

		TextBox::TextBox() {
			in.Type(InputType::Text);
		}
		TextBox::~TextBox() {}

		void TextBox::SetText(String & txt) {
			in.Value(txt);
		}

		String TextBox::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}

	}
}