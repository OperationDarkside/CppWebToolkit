#include "Body.h"

namespace dnc{
	namespace Web{
		Body::Body(){
			this->html_part1 = new String("<body>");
			this->html_part2 = new String("</body>");
		}


		Body::~Body(){}
	}
}