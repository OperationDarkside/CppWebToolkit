#include "Thead.h"

namespace dnc {
	namespace Web {


		Thead::Thead() {
			this->html_part1 = "<thead>";
			this->html_part2 = "</thead>";
		}


		Thead::~Thead() {}

		std::string Thead::ToString() {
			return std::string("System.Web.Thead");
		}
		std::string Thead::GetTypeString() {
			return std::string("Thead");
		}
	}
}