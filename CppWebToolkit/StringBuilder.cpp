#include "StringBuilder.h"



StringBuilder::StringBuilder() {}


StringBuilder::~StringBuilder() {}

std::string StringBuilder::ToString() {
	std::string res;

	res.reserve(length);

	for(auto& str : values) {
		res += str;
	}

	return res;
}

StringBuilder & StringBuilder::operator+=(const std::string & str) {
	length += str.size();
	values.push_back(str);

	return *this;
}
