#include "Paragraph.h"



Paragraph::Paragraph()
{
	this->html_part1 = new String("<p>");
	this->html_part2 = new String("</p>");
}


Paragraph::~Paragraph()
{
}

String Paragraph::toHtml()
{
	size_t len = 0;
	String str;

	len = this->children.size();

	str += this->html_part1;
	str += this->txt;
	for (size_t i = 0; i < len; i++)
	{
		str += this->children[i]->toHtml();
	}
	str += this->html_part2;

	return str;
}

void Paragraph::setText(String * _txt)
{
	this->txt = _txt;
}
