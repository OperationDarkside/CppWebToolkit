#include "VerticalLayout.h"


namespace dnc {
	namespace Web {

		VerticalLayout::VerticalLayout() {
			// root.Style(dnc::String("display: flex; flex-wrap: nowrap;"));
		}

		VerticalLayout::~VerticalLayout() {}

		std::string VerticalLayout::ToString() {
			return std::string("System.Web.VerticalLayout");
		}

		std::string VerticalLayout::GetTypeString() {
			return std::string("VerticalLayout");
		}

		String VerticalLayout::toHtml() {
			float childHeight = 100 / subElements.Count();

			for(Div div : subElements.Vector()) {
				dnc::String str = "height:";
				str += std::to_string(childHeight);
				str += "%;";
				div.Style(str);

				root.AddElement(div);
			}

			this->AddElement(root);

			return Widget::toHtml();
		}

		void VerticalLayout::toHtml(StringBuilder & sb) {
			float childHeight = 100 / subElements.Count();

			for(Div div : subElements.Vector()) {
				dnc::String str = "height:";
				str += std::to_string(childHeight);
				str += "%;";
				div.Style(str);

				root.AddElement(div);
			}

			this->AddElement(root);

			Widget::toHtml(sb);
		}

	}
}