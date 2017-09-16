#include "HtmlDataTable.h"
#include "Th.h"
#include "Thead.h"
#include "Tbody.h"
#include "Td.h"
#include "Tr.h"

namespace dnc {
	namespace Web {

		HtmlDataTable::HtmlDataTable() {}

		HtmlDataTable::~HtmlDataTable() {}

		std::string HtmlDataTable::ToString() {
			return std::string("System.Web.HtmlDataTable");
		}

		std::string HtmlDataTable::GetTypeString() {
			return std::string("HtmlDataTable");
		}

		void HtmlDataTable::FromDataTable(Data::DataTable & table) {
			long numCols = 0;
			long numRows = 0;
			Tr headRow;
			Thead head;
			Tbody body;
			Table htable;

			numCols = table.Columns().Count();
			numRows = table.Rows().Count();

			// TABLE HEAD
			for(long i = 0; i < numCols; i++) {
				Th headCell;

				headCell.InnerText(table.Columns()[i].ColumnName());

				headRow.AddElement(headCell);
			}
			head.AddElement(headRow);
			htable.AddElement(head);

			// TABLE BODY
			for(long i = 0; i < numRows; i++) {
				Tr row;

				for(long g = 0; g < numCols; g++) {
					Td cell;

					cell.InnerText(String(&table[i][g]->ToString()));

					row.AddElement(cell);
				}

				body.AddElement(row);
			}
			htable.AddElement(body);

			this->AddElement(htable);
		}
	}
}