#include "FORM.h"

namespace dnc{
	namespace Web{
		Form::Form(){
			this->html_part1 = "<form>";
			this->html_part2 = "</form>";
		}


		Form::~Form(){}

		String & Form::AcceptCharset(){
			return this->acceptCharset;
		}

		void Form::AcceptCharset(String & value){
			this->acceptCharset = value;
		}

		String & Form::Action(){
			return this->action;
		}

		void Form::Action(String & value){
			this->action = value;
		}

		bool Form::AutoComplete(){
			return this->autocomplete == 1 ? true : false;
		}

		void Form::AutoComplete(bool value){
			this->autocomplete = value ? 1 : 2;
		}

		String & Form::Enctype(){
			return this->enctype;
		}

		void Form::Enctype(String & value){
			this->enctype = value;
		}

		String & Form::Method(){
			return this->method;
		}

		void Form::Method(String & value){
			this->method = value;
		}

		String & Form::Name(){
			return this->name;
		}

		void Form::Name(String & value){
			this->name = value;
		}

		bool Form::Novalidate(){
			return this->novalidate;
		}

		void Form::Novalidate(bool value){
			this->novalidate = value;
		}

		String & Form::Target(){
			return this->target;
		}

		void Form::Target(String & value){
			this->target = value;
		}

		std::string Form::ToString(){
			return std::string("System.Html.FORM");
		}

		std::string Form::GetTypeString(){
			return std::string("FORM");
		}

		String Form::getAttributeString(){
			String res;

			res = " " + HtmlElement::getAttributeString();

			// ACCEPT CHARSET
			if(this->acceptCharset != "") {
				res += " accept-charset=\"" + this->acceptCharset + "\"";
			}

			// ACTION
			if(this->action != "") {
				res += " action=\"" + this->action + "\"";
			}

			// AUTOCOMPLETE
			if(this->autocomplete != 0) {
				res += " autocomplete=\"";
				res += (this->autocomplete == 1 ? "on" : "off");
				res += "\"";
			}

			// ENCTYPE
			if(this->enctype != "") {
				res += " enctype=\"" + this->enctype + "\"";
			}

			// METHOD
			if(this->method != ""){
				res += " method=\"" + this->method + "\"";
			}

			// NAME
			if(this->name != "") {
				res += " name=\"" + this->name + "\"";
			}

			//NOVALIDATE
			if(this->novalidate) {
				res += " novalidate";
			}

			// TARGET
			if(this->target != "") {
				res += " target=\"" + this->target + "\"";
			}

			return res;
		}
	}
}