#include "PasswordField.h"

namespace dnc {
	namespace Web {

		PasswordField::PasswordField() {
			in.Type(InputType::Password);
		}

		PasswordField::~PasswordField() {}

		std::string PasswordField::ToString() {
			return std::string("System.Web.PasswordField");
		}

		std::string PasswordField::GetTypeString() {
			return std::string("PasswordField");
		}

		String & PasswordField::Text() {
			return in.Value();
		}

		void PasswordField::Text(String & txt) {
			in.Value(txt);
		}

		String PasswordField::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}
		void PasswordField::toHtml(StringBuilder & sb) {
			this->AddElement(in);

			Widget::toHtml(sb);
		}
	}
}