#include "DotNetClone\String.h"
#include <map>

#pragma once
class POST
{
public:
	POST();
	~POST();

	void setMap(map<string, string> m);

	String operator [](char* key);
	String operator [](std::string& key);
	String operator [](String& key);

private:
	map<string, string> kv_map;
};

