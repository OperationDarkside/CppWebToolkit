#pragma once

#ifndef WIDGET_H
#define WIDGET_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Widget : public HtmlElement {
		public:
			Widget();
			virtual ~Widget();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String toHtml() override;
		};

	}
}
#endif // !WIDGET_H