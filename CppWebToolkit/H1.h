#pragma once

#ifndef H1_H
#define H1_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class H1: public HtmlElement{
		public:
			H1();
			~H1();

			std::string ToString() override;
			std::string GetTypeString() override;

			// INNER TEXT
			String InnerText();
			void InnerText(String value);
		};
	}
}
#endif