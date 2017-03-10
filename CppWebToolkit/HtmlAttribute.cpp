#include "HtmlAttribute.h"



HtmlAttribute::HtmlAttribute(){}

HtmlAttribute::HtmlAttribute(String & name, String & value): name(name), value(value){

}


HtmlAttribute::~HtmlAttribute(){}

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
