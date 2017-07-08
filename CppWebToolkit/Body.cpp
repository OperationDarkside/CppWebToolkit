#include "Body.h"

namespace dnc{
	namespace Web{

		Body::Body(){
			this->html_part1 = new String("<body>");
			this->html_part2 = new String("</body>");
		}

		Body::~Body(){}

		std::string Body::ToString() {
			return std::string("System.Web.Body");
		}
		std::string Body::GetTypeString() {
			return std::string("Body");
		}
	}
}