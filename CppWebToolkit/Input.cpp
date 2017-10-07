#include "Input.h"

namespace dnc {
	namespace Web {

		Input::Input() {
			this->html_part1 = "<input>";
			this->html_part2 = "</input>";
		}


		Input::~Input() {}
		std::string Input::ToString() {
			return std::string("System.Web.Input");
		}
		std::string Input::GetTypeString() {
			return std::string("Input");
		}

		String & Input::Accept() {
			return this->accept;
		}
		void Input::Accept(String value) {
			this->accept = value;
		}
		String & Input::Alt() {
			return this->alt;
		}
		void Input::Alt(String value) {
			this->alt = value;
		}
		bool Input::AutoComplete() {
			return this->autocomplete;
		}
		void Input::AutoComplete(bool value) {
			this->autocomplete = value;
		}
		bool Input::AutoFocus() {
			return this->autofocus;
		}
		void Input::AutoFocus(bool value) {
			this->autofocus = value;
		}
		bool Input::Checked() {
			return this->checked;
		}
		void Input::Checked(bool value) {
			this->checked = value;
		}
		bool Input::DirName() {
			return this->dirname;
		}
		void Input::DirName(bool value) {
			this->dirname = value;
		}
		bool Input::Disabled() {
			return this->disabled;
		}
		void Input::Disabled(bool value) {
			this->disabled = value;
		}
		String & Input::Form() {
			return this->form;
		}
		void Input::Form(String value) {
			this->form = value;
		}
		String & Input::FormAction() {
			return this->formaction;
		}
		void Input::FormAction(String value) {
			this->formaction = value;
		}
		String & Input::FormEncType() {
			return this->formenctype;
		}
		void Input::FormEnctType(String value) {
			this->formenctype = value;
		}
		FormMethods Input::FormMethod() {
			return this->formmeth;
		}
		void Input::FormMethod(FormMethods value) {
			this->formmeth = value;
		}
		bool Input::FormNoValidate() {
			return this->formnovalidate;
		}
		void Input::FormNoValidate(bool value) {
			this->formnovalidate = value;
		}
		String & Input::FormTarget() {
			return this->formtarget;
		}
		void Input::FormTarget(String value) {
			this->formtarget = value;
		}
		String & Input::Height() {
			return this->height;
		}
		void Input::Height(String value) {
			this->height = value;
		}
		String & Input::List() {
			return this->list;
		}
		void Input::List(String value) {
			this->list = value;
		}
		String & Input::Max() {
			return this->max;
		}
		void Input::Max(String value) {
			this->max = value;
		}
		int Input::MaxLength() {
			return this->maxlength;
		}
		void Input::MaxLength(int value) {
			this->maxlength = value;
		}
		String & Input::Min() {
			return this->min;
		}
		void Input::Min(String value) {
			this->min = value;
		}
		bool Input::Multiple() {
			return this->multiple;
		}
		void Input::Multiple(bool value) {
			this->multiple = value;
		}
		String & Input::Name() {
			return this->name;
		}
		void Input::Name(String value) {
			this->name = value;
		}
		String & Input::Pattern() {
			return this->pattern;
		}
		void Input::Pattern(String value) {
			this->pattern = value;
		}
		String & Input::Placeholder() {
			return this->placeholder;
		}
		void Input::Placeholder(String value) {
			this->placeholder = value;
		}
		bool Input::Readonly() {
			return this->readonly;
		}
		void Input::Readonly(bool value) {
			this->readonly = value;
		}
		bool Input::Required() {
			return this->required;
		}
		void Input::Required(bool value) {
			this->required = value;
		}
		int Input::Size() {
			return this->size;
		}
		void Input::Size(int value) {
			this->size = value;
		}
		String & Input::Source() {
			return this->src;
		}
		void Input::Source(String value) {
			this->src = value;
		}
		int Input::Step() {
			return this->step;
		}
		void Input::Step(int value) {
			this->step = value;
		}
		InputType Input::Type() {
			return this->type;
		}
		void Input::Type(InputType value) {
			this->type = value;
		}
		String & Input::Value() {
			return this->value;
		}
		void Input::Value(String value) {
			this->value = value;
		}
		String & Input::Width() {
			return this->width;
		}
		void Input::Width(String value) {
			this->width = value;
		}


		String Input::getAttributeString() {
			String res;

			res = " " + HtmlElement::getAttributeString();

			// ACCEPT
			if(this->accept != "") {
				res += " accept=\"" + this->accept + "\"";
			}
			// ALT
			if(this->alt != "") {
				res += " alt=\"" + this->alt + "\"";
			}
			// AUTOCOMPLETE
			if(this->autocomplete != 0) {
				res += " autocomplete=\"";
				res += (this->autocomplete == 1 ? "on" : "off");
				res += "\"";
			}
			// AUTOFOCUS
			if(this->autofocus) {
				res += " autofocus";
			}
			// CHECKED
			if(this->checked) {
				res += " checked";
			}
			// DIRNAME
			if(this->dirname) {
				res += " dirname=\"" + this->name + ".dir\"";
			}
			// DISABLED
			if(this->disabled) {
				res += " disabled";
			}
			// FORM
			if(this->form != "") {
				res += " form=\"" + this->form + "\"";
			}
			// FORMACTION
			if(this->formaction != "") {
				res += " formaction=\"" + this->formaction + "\"";
			}
			// FORMENCTYPE
			if(this->formenctype != "") {
				res += " formenctype=\"" + this->formenctype + "\"";
			}
			// FORMMETHOD
			if(this->formmeth != FormMethods::None) {
				res += " formmethod=\"";

				switch(this->formmeth) {
					case FormMethods::Get:
						res += "get\"";
						break;
					case FormMethods::Post:
						res += "post\"";
						break;
				}
				res += "\"";
			}
			// FORMNOVALIDATE
			if(this->formnovalidate) {
				res += " formnovalidate";
			}
			// FORMTARGET
			if(this->formtarget != "") {
				res += " formtarget=\"" + this->formtarget + "\"";
			}
			// HEIGHT
			if(this->height != "") {
				res += " height=\"" + this->height + "\"";
			}
			// DATALIST
			if(this->list != "") {
				res += " list=\"" + this->list + "\"";
			}
			// MAX
			if(this->max != "") {
				res += " max=\"" + this->max + "\"";
			}
			// MAXLENGTH
			if(this->maxlength != -1) {
				res += " maxlength=\"" + std::to_string(this->maxlength) + "\"";
			}
			// MIN
			if(this->min != "") {
				res += " min=\"" + this->min + "\"";
			}
			// MULTIPLE
			if(this->multiple) {
				res += " multiple";
			}
			// NAME
			if(this->name != "") {
				res += " name=\"" + this->name + "\"";
			}
			// PATTERN
			if(this->pattern != "") {
				res += " pattern=\"" + this->pattern + "\"";
			}
			// PLACEHOLDER
			if(this->placeholder != "") {
				res += " placeholder=\"" + this->placeholder + "\"";
			}
			// READONLY
			if(this->readonly) {
				res += " readonly";
			}
			// REQUIRED
			if(this->required) {
				res += " required";
			}
			// SIZE
			if(this->size != -1) {
				res += " size=\"" + std::to_string(this->size) + "\"";
			}
			// SOURCE
			if(this->src != "") {
				res += " src=\"" + this->src + "\"";
			}
			// STEP
			if(this->step != -1) {
				res += " step=\"" + std::to_string(this->step) + "\"";
			}

			res += " type=\"";
			switch(this->type) {
				case InputType::Button:
					res += "button";
					break;
				case InputType::Checkbox:
					res += "checkbox";
					break;
				case InputType::Color:
					res += "color";
					break;
				case InputType::Date:
					res += "date";
					break;
				case InputType::DateTimeLocal:
					res += "datetime-local";
					break;
				case InputType::Email:
					res += "email";
					break;
				case InputType::File:
					res += "file";
					break;
				case InputType::Hidden:
					res += "hidden";
					break;
				case InputType::Image:
					res += "image";
					break;
				case InputType::Month:
					res += "month";
					break;
				case InputType::Number:
					res += "number";
					break;
				case InputType::Password:
					res += "password";
					break;
				case InputType::Radio:
					res += "radio";
					break;
				case InputType::Range:
					res += "range";
					break;
				case InputType::Reset:
					res += "reset";
					break;
				case InputType::Search:
					res += "search";
					break;
				case InputType::Submit:
					res += "submit";
					break;
				case InputType::Tel:
					res += "tel";
					break;
				case InputType::Text:
					res += "text";
					break;
				case InputType::Time:
					res += "time";
					break;
				case InputType::Url:
					res += "url";
					break;
				case InputType::Week:
					res += "week";
					break;
			}
			res += "\"";

			// VALUE
			if(this->value != "") {
				res += " value=\"" + this->value + "\"";
			}
			// WIDTH
			if(this->width != "") {
				res += " width=\"" + this->width + "\"";
			}

			return res;
		}
	}
}