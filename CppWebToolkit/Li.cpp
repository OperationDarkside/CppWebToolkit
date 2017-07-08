#include "Li.h"


namespace dnc{
	namespace Web{

		Li::Li(){
			this->html_part1 = "<li>";
			this->html_part2 = "</li>";
		}


		Li::~Li(){}

		std::string Li::ToString(){
			return std::string("System.Web.Li");
		}
		std::string Li::GetTypeString(){
			return std::string("Li");
		}

		String Li::Value(){
			return this->value;
		}
		void Li::Value(String val){
			this->value = val;
		}

		void Li::SetText(String txt){
			this->innerText = txt;
		}

		String Li::getAttributeString(){
			String res;

			res = HtmlElement::getAttributeString();

			if(this->value != ""){
				res += " value=\"" + this->value + "\" ";
			}

			return res;
		}
	}
}