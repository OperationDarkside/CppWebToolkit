#pragma once

#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		enum wrap {
			hard,
			soft,
			none
		};

		class TextArea : public HtmlElement {
		public:
			TextArea();
			~TextArea();

			std::string ToString() override;
			std::string GetTypeString() override;

			bool Autofocus();
			void Autofocus(bool value);

			int Cols();
			void Cols(int value);

			String& Dirname();
			void Dirname(String& value);

			bool Disabled();
			void Disabled(bool value);

			String& Form();
			void Form(String& value);

			int Maxlength();
			void Maxlength(int value);

			String& Name();
			void Name(String& value);

			String& Placeholder();
			void Placeholder(String& value);

			bool Readonly();
			void Readonly(bool value);

			bool Required();
			void Required(bool value);

			int Rows();
			void Rows(int value);

			wrap Wrap();
			void Wrap(wrap value);

		private:
			bool autofocus = false;
			int cols = 0;
			String dirname;
			bool disabled = false;
			String form;
			int maxlength = 0;
			String name;
			String placeholder;
			bool readonly = false;
			bool required = false;
			int rows = 0;
			wrap wrap_value = wrap::none;

			String getAttributeString() override;
		};
	}
}
#endif // TEXTAREA_H