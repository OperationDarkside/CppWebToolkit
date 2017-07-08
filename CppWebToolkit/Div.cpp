#include "Div.h"

namespace dnc{
	namespace Web{

		Div::Div(){
			this->html_part1 = "<div>";
			this->html_part2 = "</div>";
		}


		Div::~Div(){}
		std::string Div::ToString(){
			return std::string("System.Web.Div");
		}
		std::string Div::GetTypeString(){
			return std::string("Div");
		}

		String Div::InnerText(){
			return this->innerText;
		}
		void Div::InnerText(String value){
			this->innerText = value;
		}
		
	}
}