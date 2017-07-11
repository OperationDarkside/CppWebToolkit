#pragma once

#ifndef TD_H
#define TD_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Td : public HtmlElement {
		public:
			Td();
			~Td();

			std::string ToString() override;
			std::string GetTypeString() override;

			int ColSpan();
			void ColSpan(int value);

			String Headers();
			void Headers(String value);

			// INNER TEXT
			String InnerText();
			void InnerText(String value);

			int RowSpan();
			void RowSpan(int value);

		private:
			int colspan = -1;
			String headers;
			int rowspan = -1;
		protected:
			String getAttributeString() override;
		};
	}
}
#endif