#include "HtmlElement.h"

#pragma once
class H1 : public HtmlElement
{
public:
	H1();
	~H1();
	String toHtml();

	void setText(String* _txt);
protected:
	String txt;
};

