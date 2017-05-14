#include "Div.h"

namespace dnc{
	namespace Web{

		Div::Div(){}


		Div::~Div(){}
		std::string Div::ToString(){
			return std::string("System.Web.Div");
		}
		std::string Div::getTypeString(){
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