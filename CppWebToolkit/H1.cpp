#include "H1.h"

namespace dnc{
	namespace Web{
		H1::H1(){
			this->html_part1 = new String("<h1>");
			this->html_part2 = new String("</h1>");
		}

		H1::~H1(){}

		String H1::InnerText(){
			return this->innerText;
		}

		void H1::InnerText(String value){
			this->innerText = value;
		}
	}
}