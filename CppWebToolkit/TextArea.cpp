#include "TextArea.h"

namespace dnc {
	namespace Web {

		TextArea::TextArea() {}


		TextArea::~TextArea() {}

		std::string TextArea::ToString() {
			return std::string("System.Web.TextArea");
		}

		std::string TextArea::GetTypeString() {
			return std::string("TextArea");
		}

		bool dnc::Web::TextArea::Autofocus() {
			return this->autofocus;
		}

		void dnc::Web::TextArea::Autofocus(bool value) {
			this->autofocus = value;
		}

		int dnc::Web::TextArea::Cols() {
			return this->cols;
		}

		void dnc::Web::TextArea::Cols(int value) {
			this->cols = value;
		}

		String& dnc::Web::TextArea::Dirname() {
			return this->dirname;
		}

		void dnc::Web::TextArea::Dirname(String& value) {
			this->dirname = value;
		}

		bool dnc::Web::TextArea::Disabled() {
			return this->disabled;
		}

		void dnc::Web::TextArea::Disabled(bool value) {
			this->disabled = value;
		}

		String& dnc::Web::TextArea::Form() {
			return this->form;
		}

		void dnc::Web::TextArea::Form(String& value) {
			this->form = value;
		}

		int dnc::Web::TextArea::Maxlength() {
			return this->maxlength;
		}

		void dnc::Web::TextArea::Maxlength(int value) {
			this->maxlength = value;
		}

		String& dnc::Web::TextArea::Name() {
			return this->name;
		}

		void dnc::Web::TextArea::Name(String& value) {
			this->name = value;
		}

		String& dnc::Web::TextArea::Placeholder() {
			return this->placeholder;
		}

		void dnc::Web::TextArea::Placeholder(String& value) {
			this->placeholder = value;
		}

		bool dnc::Web::TextArea::Readonly() {
			return this->readonly;
		}

		void dnc::Web::TextArea::Readonly(bool value) {
			this->readonly = value;
		}

		bool dnc::Web::TextArea::Required() {
			return this->required;
		}

		void dnc::Web::TextArea::Required(bool value) {
			this->required = value;
		}

		int dnc::Web::TextArea::Rows() {
			return this->rows;
		}

		void dnc::Web::TextArea::Rows(int value) {
			this->rows = value;
		}

		wrap dnc::Web::TextArea::Wrap() {
			return this->wrap_value;
		}

		void dnc::Web::TextArea::Wrap(wrap value) {
			this->wrap_value = value;
		}
		String TextArea::getAttributeString() {
			String res;

			res = " " + HtmlElement::getAttributeString();

			// AUTOFOCUS
			if(autofocus) {
				res += " autofocus";
			}
			// COLS
			if(cols > 0) {
				res += " cols=\"";
				res += cols;
				res += "\"";
			}
			// DIRNAME
			if(dirname != "") {
				res += " dirname=\"";
				res += dirname;
				res += "\"";
			}
			// DISABLED
			if(disabled) {
				res += " disabled";
			}
			// FORM
			if(form != "") {
				res += " form=\"";
				res += form;
				res += "\"";
			}
			// MAXLENGTH
			if(maxlength > 0) {
				res += " maxlength=\"";
				res += maxlength;
				res += "\"";
			}
			// NAME
			if(name != "") {
				res += " name=\"";
				res += name;
				res += "\"";
			}
			// PLACEHOLDER
			if(placeholder != "") {
				res += " placeholder=\"";
				res += placeholder;
				res += "\"";
			}
			// READONLY
			if(readonly) {
				res += " readonly";
			}
			// DISABLED
			if(required) {
				res += " required";
			}
			// ROWS
			if(rows > 0) {
				res += " rows=\"";
				res += rows;
				res += "\"";
			}
			// WRAP
			if(wrap_value != wrap::none) {
				if(wrap_value == wrap::hard) {
					res += " wrap=\"hard\"";
				} else {
					res += " wrap=\"soft\"";
				}
			}

			return res;
		}
	}
}