#include "Widget.h"

namespace dnc {
	namespace Web {

		Widget::Widget() {}


		Widget::~Widget() {}

		std::string Widget::ToString() {
			return std::string("System.Web.Widget");
		}

		std::string Widget::GetTypeString() {
			return std::string("Widget");
		}

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

		void Widget::toHtml(StringBuilder & sb) {
			size_t len_SubElements = 0;
			String str;

			len_SubElements = this->children.Count();
			for(size_t i = 0; i < len_SubElements; i++) {
				HtmlElement* ele = this->children[i].get();

				ele->toHtml(sb);
			}
		}

	}
}