#include "GridLayout.h"

namespace dnc {
	namespace Web {

		GridLayout::GridLayout() {
			root.Style(dnc::String("height: 100%; width: 100%; display: grid;"));
		}


		GridLayout::~GridLayout() {}

		std::string dnc::Web::GridLayout::ToString() {
			return std::string("System.Web.GridLayout");
		}

		std::string dnc::Web::GridLayout::GetTypeString() {
			return std::string("GridLayout");
		}

		String dnc::Web::GridLayout::toHtml() {
			for(Div div : subElements.Vector()) {
				root.AddElement(div);
			}

			dnc::String rowTempl = "grid-template-columns: ";
			for(dnc::String rowT : rowTemplates.Vector()) {
				rowTempl += rowT;
				rowTempl += " ";
			}
			rowTempl += ";";

			dnc::String colTempl = "grid-template-rows: ";
			for(dnc::String colT : columnTemplates.Vector()) {
				colTempl += colT;
				colTempl += " ";
			}
			colTempl += ";";

			root.Style(root.Style() + rowTempl + colTempl);

			this->AddElement(root);

			return Widget::toHtml();
		}

		void GridLayout::toHtml(StringBuilder & sb) {
			for(Div div : subElements.Vector()) {
				root.AddElement(div);
			}

			dnc::String rowTempl = "grid-template-columns: ";
			for(dnc::String rowT : rowTemplates.Vector()) {
				rowTempl += rowT;
				rowTempl += " ";
			}
			rowTempl += ";";

			dnc::String colTempl = "grid-template-rows: ";
			for(dnc::String colT : columnTemplates.Vector()) {
				colTempl += colT;
				colTempl += " ";
			}
			colTempl += ";";

			root.Style(root.Style() + rowTempl + colTempl);

			this->AddElement(root);

			Widget::toHtml(sb);
		}

		void GridLayout::AddRowTemplate(dnc::String& templ) {
			rowTemplates.Add(templ);
		}

		void GridLayout::AddColumnTemplate(dnc::String& templ) {
			columnTemplates.Add(templ);
		}

		void GridLayout::SetRowTemplates(std::vector<dnc::String> templates) {
			rowTemplates.Vector(templates);
		}

		void GridLayout::SetColumnTemplates(std::vector<dnc::String> templates) {
			columnTemplates.Vector(templates);
		}

		void GridLayout::SetColumnGap(dnc::String& gap) {
			colGap = gap;
		}

		void GridLayout::SetRowGap(dnc::String& gap) {
			rowGap = gap;
		}
	}
}