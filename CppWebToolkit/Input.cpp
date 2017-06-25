#include "Input.h"

namespace dnc {
	namespace Web {

		Input::Input() {
			this->html_part1 = "<input>";
			this->html_part2 = "</input>";
		}


		Input::~Input() {}
		std::string Input::ToString() {
			return std::string("System.Html.Input");
		}
		std::string Input::GetTypeString() {
			return std::string("Input");
		}

		String & Input::Accept() {
			return this->accept;
		}
		void Input::Accept(String value) {}
		String & Input::Alt() {
			return this->alt;
		}
		void Input::Alt(String value) {}
		bool Input::AutoComplete() {
			return this->autocomplete;
		}
		void Input::AutoComplete(bool value) {}
		bool Input::AutoFocus() {
			return this->autofocus;
		}
		void Input::AutoFocus(bool value) {}
		bool Input::Checked() {
			return this->checked;
		}
		void Input::Checked(bool value) {}
		bool Input::DirName() {
			return this->dirname;
		}
		void Input::DirName(bool value) {}
		bool Input::Disabled() {
			return this->disabled;
		}
		void Input::Disabled(bool value) {}
		String & Input::Form() {
			return this->form;
		}
		void Input::Form(String value) {}
		String & Input::FormAction() {
			return this->formaction;
		}
		void Input::FormAction(String value) {}
		String & Input::FormEncType() {
			return this->formenctype;
		}
		void Input::FormEnctType(String value) {}
		FormMethods Input::FormMethod() {
			return this->formmethod;
		}
		void Input::FormMethod(FormMethods value) {}
		bool Input::FormNoValidate() {
			return this->formnovalidate;
		}
		void Input::FormNoValidate(bool value) {}
		String & Input::FormTarget() {
			return this->formtarget;
		}
		void Input::FormTarget(String value) {}
		String & Input::Height() {
			return this->height;
		}
		void Input::Height(String value) {}
		String & Input::List() {
			return this->list;
		}
		void Input::List(String value) {}
		String & Input::Max() {
			return this->max;
		}
		void Input::Max(String value) {}
		bool Input::Multiple() {
			return this->multiple;
		}
		void Input::Multiple(bool value) {}
		String & Input::Name() {
			return this->name;
		}
		void Input::Name(String value) {}
		String & Input::Pattern() {
			return this->pattern;
		}
		void Input::Pattern(String value) {}
		String & Input::Placeholder() {
			return this->placeholder;
		}
		void Input::Placeholder(String value) {}
		bool Input::Readonly() {
			return this->readonly;
		}
		void Input::Readonly(bool value) {}
		bool Input::Required() {
			return this->required;
		}
		void Input::Required(bool value) {}
		unsigned Input::Size() {
			return this->size;
		}
		void Input::Size(unsigned value) {}
		String & Input::Source() {
			return this->src;
		}
		void Input::Source(String value) {}
		int Input::Step() {
			return this->step;
		}
		void Input::Step(int value) {}
		InputType Input::Type() {
			return this->type;
		}
		void Input::Type(InputType value) {}
		String & Input::Value() {
			return this->value;
		}
		void Input::Value(String value) {}
		String & Input::Width() {
			return this->width;
		}
		void Input::Width(String value) {}
	}
}