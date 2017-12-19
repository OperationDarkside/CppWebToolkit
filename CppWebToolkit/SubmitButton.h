#pragma once

#ifndef SUBMITBUTTON_H
#define SUBMITBUTTON_H

#include "Widget.h"
#include "Input.h"

namespace dnc {
	namespace Web {
		class SubmitButton : public Widget {
		public:
			SubmitButton();
			SubmitButton(String& _caption);
			~SubmitButton();

			std::string ToString() override;
			std::string GetTypeString() override;

			String& Caption();
			void Caption(String& _caption);

			virtual String toHtml() override;
			virtual void toHtml(StringBuilder& sb) override;
		private:
			Input in;
		};
	}
}

#endif