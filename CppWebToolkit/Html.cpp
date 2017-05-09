#include "Html.h"

namespace dnc{
	namespace Web{
		Html::Html(){
			this->html_part1 = new String("<html>");
			this->html_part1 += String("<head><title>Testseite</title><meta charset=\"utf-8\"></head>");

			this->html_part2 = new String("</html>");


		}


		Html::~Html(){}
	}
}