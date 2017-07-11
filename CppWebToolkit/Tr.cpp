#include "Tr.h"

namespace dnc {
	namespace Web {

		Tr::Tr() {
			this->html_part1 = new String("<tr>");
			this->html_part2 = new String("</tr>");
		}


		Tr::~Tr() {}

		std::string dnc::Web::Tr::ToString() {
			return std::string("System.Web.Tr");
		}

		std::string dnc::Web::Tr::GetTypeString() {
			return std::string("Tr");
		}

	}
}