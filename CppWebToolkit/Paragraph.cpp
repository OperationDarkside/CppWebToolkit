#include "Paragraph.h"

namespace dnc{
	namespace Web{

		Paragraph::Paragraph(){
			this->html_part1 = new String("<p>");
			this->html_part2 = new String("</p>");
		}
		Paragraph::~Paragraph(){}


		String Paragraph::InnerText(){
			return this->innerText;
		}
		void Paragraph::InnerText(String value){
			this->innerText = value;
		}

	}
}