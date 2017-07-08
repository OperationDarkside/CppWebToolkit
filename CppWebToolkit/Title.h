#pragma once

#ifndef TITLE_H
#define TITLE_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		class Title: public HtmlElement{
		public:
			Title();
			~Title();

			std::string ToString() override;
			std::string GetTypeString() override;

			//String toHtml() override;

			void SetText(String value);

		private:
			//String text;
		};
	}
}
#endif