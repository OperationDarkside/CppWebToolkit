#include "Head.h"

namespace dnc{
	namespace Web{

		Head::Head(){
			this->html_part1 = "<head>";
			this->html_part2 = "</head>";
		}


		Head::~Head(){}
		std::string Head::ToString() {
			return std::string("System.Web.Head");
		}
		std::string Head::GetTypeString() {
			return std::string("Head");
		}
	}
}