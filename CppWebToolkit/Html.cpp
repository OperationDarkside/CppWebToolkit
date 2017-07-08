#include "Html.h"

namespace dnc{
	namespace Web{
		Html::Html(){
			this->html_part1 = new String("<!DOCTYPE html><html>");
			//this->html_part1 += String("<head><title>Testseite</title><meta charset=\"utf-8\"></head>");

			this->html_part2 = new String("</html>");


		}


		Html::~Html(){}
		std::string Html::ToString() {
			return std::string("System.Web.Html");
		}
		std::string Html::GetTypeString() {
			return std::string("Html");
		}
	}
}