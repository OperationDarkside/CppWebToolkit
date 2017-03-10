#include "GET.h"
#include "POST.h"

#pragma once
class Request
{
public:
	Request();
	~Request();

	void GetEnv();

	GET GetValues();
	POST PostValues();

private:
	string UriDecode(const string& sSrc);

	map<string, string> get_kvs;
	map<string, string> post_kvs;
};

