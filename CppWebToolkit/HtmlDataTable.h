#pragma once

#ifndef HTMLDATATABLE_H
#define HTMLDATATABLE_H

#include "Widget.h"
#include "Table.h"
#include "DNC\DataTable.h"

namespace dnc {
	namespace Web {
		class HtmlDataTable : public Widget {
		public:
			HtmlDataTable();
			~HtmlDataTable();

			void FromDataTable(Data::DataTable& table);

		};
	}
}
#endif // !HTMLDATATABLE_H