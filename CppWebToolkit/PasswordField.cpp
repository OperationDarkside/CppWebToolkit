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

		void PasswordField::SetText(String & txt) {
			in.Value(txt);
		}

		String PasswordField::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}
	}
}