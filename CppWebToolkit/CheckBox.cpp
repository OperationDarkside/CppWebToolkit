#include "CheckBox.h"

namespace dnc {
	namespace Web {

		CheckBox::CheckBox() {
			in.Type(InputType::Checkbox);
		}

		CheckBox::~CheckBox() {}


		std::string CheckBox::ToString() {
			return std::string("System.Web.CheckBox");
		}

		std::string CheckBox::GetTypeString() {
			return std::string("CheckBox");
		}

		bool CheckBox::Checked() {
			return in.Checked();
		}

		void CheckBox::Checked(bool value) {
			in.Checked(value);
		}

		String CheckBox::toHtml() {
			this->AddElement(in);

			return Widget::toHtml();
		}

	}
}