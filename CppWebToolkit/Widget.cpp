#include "Widget.h"

namespace dnc {
	namespace Web {

		Widget::Widget() {}


		Widget::~Widget() {}

		String Widget::toHtml() {
			size_t len_SubElements = 0;
			String str;

			len_SubElements = this->children.Count();
			for(size_t i = 0; i < len_SubElements; i++) {
				HtmlElement* ele = this->children[i].get();

				str += ele->toHtml();
			}

			return str;
		}

	}
}