#include "HtmlDataAttribute.h"

namespace dnc{
	namespace Web{
		HtmlDataAttribute::HtmlDataAttribute(){}

		HtmlDataAttribute::HtmlDataAttribute(String & name, String & value): name(name), value(value){}


		HtmlDataAttribute::~HtmlDataAttribute(){}

		std::string HtmlDataAttribute::ToString(){
			return std::string("System.Web.HtmlDataAttribute");
		}

		std::string HtmlDataAttribute::GetTypeString(){
			return std::string("HtmlDataAttribute");
		}

		String & HtmlDataAttribute::Name(){
			return this->name;
		}

		void HtmlDataAttribute::Name(String & name){
			this->name = name;
		}

		String & HtmlDataAttribute::Value(){
			return this->value;
		}

		void HtmlDataAttribute::Value(String & value){
			this->value = value;
		}
	}
}