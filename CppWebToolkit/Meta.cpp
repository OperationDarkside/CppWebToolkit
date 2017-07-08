#include "Meta.h"

namespace dnc{
	namespace Web{


		Meta::Meta(){
			this->html_part1 = "<meta ";
			this->html_part2 = "/>";
		}

		Meta::~Meta(){}

		std::string Meta::ToString(){
			return std::string("System.Web.Meta");
		}
		std::string Meta::GetTypeString(){
			return std::string("Meta");
		}

		CharSets Meta::CharSet(){
			return this->charset;
		}

		void Meta::CharSet(CharSets value){
			this->charset = value;
		}

		String Meta::Content(){
			return this->content;
		}

		void Meta::Content(String value){
			this->content = value;
		}

		String Meta::HttpEquiv(){
			return this->httpEquiv;
		}

		void Meta::HttpEquiv(String value){
			this->httpEquiv = value;
		}

		String Meta::Name(){
			return this->name;
		}

		void Meta::Name(String value){
			this->name = value;
		}

		String Meta::getAttributeString() {
			String cs;
			String res;

			res += HtmlElement::getAttributeString();

			if(this->charset != CharSets::None){
				switch(this->charset){
					case CharSets::UTF8:
						cs = "utf-8";
						break;
				}

				res += " charset=\"" + cs + "\" ";
			}
			if(this->content != ""){
				res += " content=\"" + this->content + "\" ";
			}
			if(this->httpEquiv != ""){
				res += " http-equiv=\"" + this->httpEquiv + "\" ";
			}
			if(this->name != ""){
				res += " name=\"" + this->name + "\" ";
			}

			return res;
		}
	}
}