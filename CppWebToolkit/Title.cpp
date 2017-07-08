#include "Title.h"

namespace dnc{
	namespace Web{

		Title::Title(){
			this->html_part1 = "<title>";
			this->html_part2 = "</title>";
		}


		Title::~Title(){}

		std::string Title::ToString(){
			return std::string("System.Web.Title");
		}

		std::string Title::GetTypeString(){
			return std::string("Title");
		}

		//String Title::toHtml(){
		//	size_t len = 0;
		//	String str;

		//	len = this->children.size();

		//	str += this->html_part1;
		//	str += this->text;
		//	for(size_t i = 0; i < len; i++){
		//		str += this->children[i]->toHtml();
		//	}
		//	str += this->html_part2;

		//	return str;
		//}

		void Title::SetText(String value){
			this->innerText = value;
		}

	}
}