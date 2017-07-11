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

			virtual String toHtml() override;
		};

	}
}
#endif // !WIDGET_H