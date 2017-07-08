#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		enum FormMethods {
			None = 0,
			Get = 1,
			Post = 2
		};
		enum InputType {
			Button = 0,
			Checkbox = 1,
			Color = 2,
			Date = 3,
			DateTimeLocal = 4,
			Email = 5,
			File = 6,
			Hidden = 7,
			Image = 8,
			Month = 9,
			Number = 10,
			Password = 11,
			Radio = 12,
			Range = 13,
			Reset = 14,
			Search = 15,
			Submit = 16,
			Tel = 17,
			Text = 18,
			Time = 19,
			Url = 20,
			Week = 21
		};

		class Input : public HtmlElement {
		public:
			Input();
			~Input();

			std::string ToString() override;
			std::string GetTypeString() override;

			String& Accept();
			void Accept(String value);
			String& Alt();
			void Alt(String value);
			bool AutoComplete();
			void AutoComplete(bool value);
			bool AutoFocus();
			void AutoFocus(bool value);
			bool Checked();
			void Checked(bool value);
			bool DirName();
			void DirName(bool value);
			bool Disabled();
			void Disabled(bool value);
			String& Form();
			void Form(String value);
			String& FormAction();
			void FormAction(String value);
			String& FormEncType();
			void FormEnctType(String value);
			FormMethods FormMethod();
			void FormMethod(FormMethods value);
			bool FormNoValidate();
			void FormNoValidate(bool value);
			String& FormTarget();
			void FormTarget(String value);
			String& Height();
			void Height(String value);
			String& List();
			void List(String value);
			String& Max();
			void Max(String value);
			int MaxLength();
			void MaxLength(int value);
			String& Min();
			void Min(String value);
			bool Multiple();
			void Multiple(bool value);
			String& Name();
			void Name(String value);
			String& Pattern();
			void Pattern(String value);
			String& Placeholder();
			void Placeholder(String value);
			bool Readonly();
			void Readonly(bool value);
			bool Required();
			void Required(bool value);
			int Size();
			void Size(int value);
			String& Source();
			void Source(String value);
			int Step();
			void Step(int value);
			InputType Type();
			void Type(InputType value);
			String& Value();
			void Value(String value);
			String& Width();
			void Width(String value);

		private:

			String accept;
			String alt;
			int autocomplete = 0;
			bool autofocus = false;
			bool checked = false;
			bool dirname = false;
			bool disabled = false;
			String form;
			String formaction;
			String formenctype;
			FormMethods formmeth;
			bool formnovalidate = false;
			String formtarget;
			String height;
			String list;
			String max;
			int maxlength = -1;
			String min;
			bool multiple = false;
			String name;
			String pattern;
			String placeholder;
			bool readonly = false;
			bool required = false;
			int size = -1;
			String src;
			int step = -1;
			InputType type;
			String value;
			String width;

		protected:
			String getAttributeString() override;
		};

		
	}
}
#endif