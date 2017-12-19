#pragma once
#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

#include <list>
#include <string>

class StringBuilder {
public:
	StringBuilder();
	~StringBuilder();

	std::string ToString();

	StringBuilder& operator +=(const std::string& str);

private:
	unsigned length = 0;
	std::list<std::string> values;
};
#endif // !STRINGBUILDER_H