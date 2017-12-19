#include "HorizontalLayout.h"

namespace dnc {
	namespace Web {

		HorizontalLayout::HorizontalLayout() {
			root.Style(dnc::String("display: flex; flex-wrap: nowrap;"));
		}


		HorizontalLayout::~HorizontalLayout() {}

		std::string HorizontalLayout::ToString() {
			return std::string("System.Web.VerticalLayout");
		}

		std::string HorizontalLayout::GetTypeString() {
			return std::string("VerticalLayout");
		}

		String HorizontalLayout::toHtml() {
			float childWidth = 100 / subElements.Count();

			for(Div div : subElements.Vector()) {
				dnc::String str = "width:";
				str += std::to_string(childWidth);
				str += "%;";
				div.Style(str);

				root.AddElement(div);
			}

			this->AddElement(root);

			return Widget::toHtml();
		}

		void HorizontalLayout::toHtml(StringBuilder & sb) {
			float childWidth = 100 / subElements.Count();

			for(Div div : subElements.Vector()) {
				dnc::String str = "width:";
				str += std::to_string(childWidth);
				str += "%;";
				div.Style(str);

				root.AddElement(div);
			}

			this->AddElement(root);

			Widget::toHtml(sb);
		}

	}
}