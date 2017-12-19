#pragma once

#ifndef PASSWORDFIELD_H
#define PASSWORDFIELD_H

#include "Widget.h"
#include "Input.h"

namespace dnc {
	namespace Web {
		class PasswordField : public Widget {
		public:
			PasswordField();
			~PasswordField();

			std::string ToString() override;
			std::string GetTypeString() override;

			String& Text();
			void Text(String& txt);

			virtual String toHtml() override;
			virtual void toHtml(StringBuilder& sb) override;
		private:
			Input in;
		};
	}
}
#endif // !PASSWORDFIELD_H