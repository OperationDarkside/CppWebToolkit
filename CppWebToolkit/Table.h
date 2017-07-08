#pragma once

#ifndef TABLE_H
#define TABLE_H

#include "HtmlElement.h"

namespace dnc {
	namespace Web {

		class Table : public HtmlElement {
		public:
			Table();
			~Table();

			std::string ToString() override;
			std::string GetTypeString() override;
		};
	}
}
#endif