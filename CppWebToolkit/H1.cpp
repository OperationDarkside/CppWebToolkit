#include "H1.h"

namespace dnc{
	namespace Web{
		H1::H1(){
			this->html_part1 = new String("<h1>");
			this->html_part2 = new String("</h1>");
		}

		H1::~H1(){}

		String H1::toHtml(){
			size_t len = 0;
			String str;

			len = this->children.size();

			str += this->html_part1;
			str += this->txt;
			for(size_t i = 0; i < len; i++){
				str += this->children[i]->toHtml();
			}
			str += this->html_part2;

			return str;
		}

		void H1::setText(String * _txt){
			this->txt = _txt;
		}
	}
}