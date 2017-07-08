#include "Tbody.h"

namespace dnc {
	namespace Web {

		Tbody::Tbody() {
			this->html_part1 = new String("<tbody>");
			this->html_part2 = new String("</tbody>");
		}

		Tbody::~Tbody() {}

		std::string Tbody::ToString() {
			return std::string("System.Web.Tbody");
		}

		std::string Tbody::GetTypeString() {
			return std::string("Tbody");
		}

	}
}