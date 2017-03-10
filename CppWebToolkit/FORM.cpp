#include "FORM.h"



FORM::FORM(){
	this->html_part1 = "<form>";
	this->html_part2 = "</form>";
}


FORM::~FORM(){}

String & FORM::AcceptCharset(){
	return this->acceptCharset;
}

void FORM::AcceptCharset(String & value){
	this->acceptCharset = value;
}

String & FORM::Action(){
	return this->action;
}

void FORM::Action(String & value){
	this->action = value;
}

bool FORM::AutoComplete(){
	return this->autocomplete == 1 ? true : false;
}

void FORM::AutoComplete(bool value){
	this->autocomplete = value ? 1 : 2;
}

String & FORM::Enctype(){
	return this->enctype;
}

void FORM::Enctype(String & value){
	this->enctype = value;
}

String & FORM::Method(){
	return this->method;
}

void FORM::Method(String & value){
	this->method = value;
}

String & FORM::Name(){
	return this->name;
}

void FORM::Name(String & value){
	this->name = value;
}

bool FORM::Novalidate(){
	return this->novalidate;
}

void FORM::Novalidate(bool value){
	this->novalidate = value;
}

String & FORM::Target(){
	return this->target;
}

void FORM::Target(String & value){
	this->target = value;
}

string FORM::toString(){
	return string("System.Html.FORM");
}

string FORM::getTypeString(){
	return string("FORM");
}

String FORM::getAttributeString(){
	String res;

	res = " " + HtmlElement::getAttributeString();
	if(this->method != ""){
		res += "method=\"" + this->method + "\" ";
	}

	return res;
}
