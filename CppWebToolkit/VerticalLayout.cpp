#include "VerticalLayout.h"

namespace dnc {
	namespace Web {

		VerticalLayout::VerticalLayout() {
			root.Style(dnc::String("display: flex; flex-wrap: nowrap;"));
		}


		VerticalLayout::~VerticalLayout() {}

		std::string VerticalLayout::ToString() {
			return std::string("System.Web.VerticalLayout");
		}

		std::string VerticalLayout::GetTypeString() {
			return std::string("VerticalLayout");
		}

		String VerticalLayout::toHtml() {
			this->AddElement(root);

			return Widget::toHtml();
		}

	}
}