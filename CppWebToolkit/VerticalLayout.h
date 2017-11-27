#pragma once

#ifndef VERTICALLAYOUT_H
#define VERTICALLAYOUT_H

#include "Div.h"
#include "Widget.h"

namespace dnc {
	namespace Web {
		class VerticalLayout : public Widget {
		public:
			VerticalLayout();
			~VerticalLayout();

			std::string ToString() override;
			std::string GetTypeString() override;

			virtual String toHtml() override;

			template <typename T>
			void AddWidget(T& component);

		private:
			Div root;
		};

		template<typename T>
		inline void VerticalLayout::AddWidget(T & component) {
			static_assert(std::is_base_of<Widget, T>::value, "VerticalLayout::AddWidget - Template does not derive from Widget.");

			root.AddElement(component);
		}
	}
}

#endif // !VERTICALLAYOUT_H