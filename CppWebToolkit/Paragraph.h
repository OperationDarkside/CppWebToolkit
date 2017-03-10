#include "HtmlElement.h"
#include "DotNetClone\String.h"

#pragma once
class Paragraph : public HtmlElement
{
public:
	Paragraph();
	~Paragraph();

	String toHtml();

	void setText(String* _txt);
protected:
	String txt;
};

