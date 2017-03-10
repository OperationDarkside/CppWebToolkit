#pragma once

#include "DotNetClone\String.h"
#include "DotNetClone\Object.h"

class HtmlAttribute{
public:
	HtmlAttribute();
	HtmlAttribute(String& name, String& value);
	~HtmlAttribute();

	String& Name();
	void Name(String& name);

	String& Value();
	void Value(String& value);
private:
	String name;
	String value;
};

