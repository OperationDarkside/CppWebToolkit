#pragma once

#ifndef P_H
#define P_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{
		class Paragraph: public HtmlElement{
		public:
			Paragraph();
			~Paragraph();

			std::string ToString() override;
			std::string GetTypeString() override;

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}
#endif