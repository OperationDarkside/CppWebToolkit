#include "TextBox.h"

namespace dnc {
	namespace Web {

		TextBox::TextBox() {
			in.Type(InputType::Text);
		}
		TextBox::~TextBox() {}

		std::string TextBox::ToString() {
			return std::string("System.Web.TextBox");
		}

		std::string TextBox::GetTypeString() {
			return std::string("TextBox");
		}

		void TextBox::SetText(String & txt) {
			in.Value(txt);
		}

		String TextBox::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}

	}
}