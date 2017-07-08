#include "Tfoot.h"

namespace dnc {
	namespace Web {

		Tfoot::Tfoot() {
			this->html_part1 = new String("<tfoot>");
			this->html_part2 = new String("</tfoot>");
		}

		Tfoot::~Tfoot() {}

		std::string Tfoot::ToString() {
			return std::string("System.Web.Tfoot");
		}

		std::string Tfoot::GetTypeString() {
			return std::string("Tfoot");
		}

	}
}