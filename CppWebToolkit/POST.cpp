#include "POST.h"

POST::POST()
{
}

POST::~POST()
{
}

void POST::setMap(map<string, string> m)
{
	this->kv_map = m;
}

String POST::operator[](char * key)
{
	return String(&this->kv_map.at(string(key)));
}

String POST::operator[](std::string & key)
{
	return String(&this->kv_map.at(key));
}

String POST::operator[](String & key)
{
	return String(&this->kv_map.at(key.getStringValue()));
}