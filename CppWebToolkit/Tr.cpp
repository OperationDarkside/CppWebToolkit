#include "Tr.h"

namespace dnc {
	namespace Web {

		Tr::Tr() {}


		Tr::~Tr() {}

		std::string dnc::Web::Tr::ToString() {
			return std::string("System.Web.Tr");
		}

		std::string dnc::Web::Tr::GetTypeString() {
			return std::string("Tr");
		}

	}
}