#pragma once

#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include "Div.h"
#include "Widget.h"

namespace dnc {
	namespace Web {
		class GridLayout : public Widget {
		public:
			GridLayout();
			~GridLayout();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String toHtml() override;

			template <typename T>
			void AddWidget(T& component, unsigned row, unsigned column, int rowSpan, int colSpan);

			void AddRowTemplate(dnc::String& templ);

			void AddColumnTemplate(dnc::String& templ);

			void SetRowTemplates(std::vector<dnc::String> templates);

			void SetColumnTemplates(std::vector<dnc::String> templates);

			void SetColumnGap(dnc::String& gap);

			void SetRowGap(dnc::String& gap);

		private:
			dnc::Collections::Generic::List<dnc::String> rowTemplates;
			dnc::Collections::Generic::List<dnc::String> columnTemplates;

			dnc::String colGap;
			dnc::String rowGap;

			dnc::Collections::Generic::List<Div> subElements;
			Div root;
		};

		template<typename T>
		inline void GridLayout::AddWidget(T & component, unsigned row, unsigned column, int rowSpan, int colSpan) {
			static_assert(std::is_base_of<HtmlElement, T>::value, "GridLayout::AddWidget - Template does not derive from HtmlElement.");
			Div childWrapper;

			std::stringstream style;
			style << "grid-column: ";
			style << column;
			if(colSpan != 0) {
				style << " / span ";
				style << colSpan;
			}
			style << "; grid-row: ";
			style << row;
			if(rowSpan != 0) {
				style << " / span ";
				style << rowSpan;
			}
			style << ";";

			childWrapper.Style(dnc::String(style.str()));

			childWrapper.AddElement(component);

			subElements.Add(childWrapper);
		}

	}
}

#endif // !GRIDLAYOUT_H