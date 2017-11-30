#pragma once

#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H

#include "Div.h"
#include "Widget.h"

namespace dnc {
	namespace Web {
		class HorizontalLayout : public Widget {
		public:
			HorizontalLayout();
			~HorizontalLayout();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String toHtml() override;

			template <typename T>
			void AddWidget(T& component);

		private:
			dnc::Collections::Generic::List<Div> subElements;
			Div root;
		};

		template<typename T>
		inline void HorizontalLayout::AddWidget(T & component) {
			static_assert(std::is_base_of<Widget, T>::value, "HorizontalLayout::AddWidget - Template does not derive from Widget.");

			Div childWrapper;
			childWrapper.AddElement(component);
			
			subElements.Add(childWrapper);
		}
	}
}

#endif // !HORIZONTALLAYOUT_H