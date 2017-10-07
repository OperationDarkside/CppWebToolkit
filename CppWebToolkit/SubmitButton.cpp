#include "SubmitButton.h"

namespace dnc {
	namespace Web {

		SubmitButton::SubmitButton() {
			in.Type(InputType::Submit);
		}

		SubmitButton::SubmitButton(String& _caption) {
			in.Value(_caption);
		}

		SubmitButton::~SubmitButton() {}


		std::string SubmitButton::ToString() {
			return std::string("System.Web.SubmitButton");
		}

		std::string SubmitButton::GetTypeString() {
			return std::string("SubmitButton");
		}

		String & SubmitButton::Caption() {
			return in.Value();
		}

		void SubmitButton::Caption(String & _caption) {
			in.Value(_caption);
		}

		String SubmitButton::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}

	}
}