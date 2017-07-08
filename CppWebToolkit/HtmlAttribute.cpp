#include "HtmlAttribute.h"

namespace dnc{
	namespace Web{
		HtmlAttribute::HtmlAttribute(){}

		HtmlAttribute::HtmlAttribute(String & name, String & value): name(name), value(value){

		}


		HtmlAttribute::~HtmlAttribute(){}

		std::string HtmlAttribute::ToString() {
			return std::string("System.Web.HtmlAttribute");
		}

		std::string HtmlAttribute::GetTypeString() {
			return std::string("HtmlAttribute");
		}

		String& HtmlAttribute::Name(){
			return this->name;
		}

		void HtmlAttribute::Name(String & name){
			this->name = name;
		}

		String& HtmlAttribute::Value(){
			return this->value;
		}

		void HtmlAttribute::Value(String& value){
			this->value = value;
		}
	}
}