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
				str += childWidth;
				str += "%;";
				div.Style(str);

				root.AddElement(div);
			}

			this->AddElement(root);

			return Widget::toHtml();
		}

	}
}