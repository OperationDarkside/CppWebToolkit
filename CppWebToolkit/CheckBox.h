#pragma once

#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Widget.h"
#include "Input.h"

namespace dnc {
	namespace Web {
		class CheckBox : public Widget {
		public:
			CheckBox();
			~CheckBox();

			std::string ToString() override;
			std::string GetTypeString() override;

			bool Checked();
			void Checked(bool value);

			virtual String toHtml() override;
			virtual void toHtml(StringBuilder& sb) override;
		private:
			Input in;
		};
	}
}
#endif