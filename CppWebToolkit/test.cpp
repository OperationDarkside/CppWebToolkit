#include <iostream>
#include "HtmlElement.h"
#include "Html.h"
#include "Body.h"
#include "H1.h"
#include "Paragraph.h"
#include "Request.h"
#include "FORM.h"

#pragma comment(lib, "DotNetClone.lib")

using namespace std;

int main() {
	Html html;
	Body body;
	Paragraph p;
	H1 h1;
	Request req;
	GET g;
	FORM form;

	putenv("QUERY_STRING=prename=Marvin&lastname=Smith");
	putenv("REQUEST_METHOD=GET");

	req.GetEnv();
	g = req.GetValues();

	h1.setText(new String(u8"ÜBASCHRIFD"));

	p.setText(new String("Hallo " + g["prename"] + g["lastname"]));

	form.Class(String("pollenstress"));
	form.Method(String("POST"));

	body.AddElement(&h1);
	body.AddElement(&p);
	body.AddElement(&form);
	html.AddElement(&body);

	cout << "Content-type:text/html\r\n\r\n";
	cout << html.toHtml().getStringValue();

}