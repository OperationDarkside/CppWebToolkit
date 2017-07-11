#pragma once

#ifndef TH_H
#define TH_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		enum Th_Scope {
			None = -1,
			Col = 0,
			ColGroup = 1,
			Row = 2,
			RowGroup = 3
		};

		class Th : public HtmlElement {
		public:
			Th();
			~Th();

			std::string ToString() override;
			std::string GetTypeString() override;

			String Abbr();
			void Abbr(String value);

			int ColSpan();
			void ColSpan(int value);

			String Headers();
			void Headers(String value);

			// INNER TEXT
			String InnerText();
			void InnerText(String value);

			int RowSpan();
			void RowSpan(int value);

			Th_Scope Scope();
			void Scope(Th_Scope value);

		private:
			String abbr;
			int colspan = -1;
			String headers;
			int rowspan = -1;
			Th_Scope scope = Th_Scope::None;
		protected:
			String getAttributeString() override;
		};
		
	}
}
#endif