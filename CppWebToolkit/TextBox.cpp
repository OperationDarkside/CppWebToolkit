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

		String & TextBox::Text() {
			return in.Value();
		}

		void TextBox::Text(String & txt) {
			in.Value(txt);
		}

		String TextBox::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}

		void TextBox::toHtml(StringBuilder & sb) {
			this->AddElement(in);

			Widget::toHtml(sb);
		}

	}
}