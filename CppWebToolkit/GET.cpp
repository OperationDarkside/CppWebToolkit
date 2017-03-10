#include "GET.h"



GET::GET()
{
}


GET::~GET()
{
}

void GET::setMap(map<string, string> m)
{
	this->kv_map = m;
}

String GET::operator[](char * key)
{
	return String(&this->kv_map.at(string(key)));
}

String GET::operator[](std::string & key)
{
	return String(&this->kv_map.at(key));
}

String GET::operator[](String & key)
{
	return String(&this->kv_map.at(key.getStringValue()));
}
