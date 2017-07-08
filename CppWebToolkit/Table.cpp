#include "Table.h"

namespace dnc {
	namespace Web {

		Table::Table() {
			this->html_part1 = "<table>";
			this->html_part2 = "</table>";
		}


		Table::~Table() {}

		std::string Table::ToString() {
			return std::string("System.Web.Table");
		}
		std::string Table::GetTypeString() {
			return std::string("Table");
		}

	}
}