#include <iostream>
#include "Html.h"
#include "Body.h"
#include "H1.h"
#include "Paragraph.h"
#include "Request.h"
#include "FORM.h"
#include "String.h"

//using namespace dnc;
//using namespace dnc::Web;


int main(){
	dnc::Web::Html html;
	dnc::Web::Body body;
	dnc::Web::Paragraph p;
	dnc::Web::H1 h1;
	dnc::Web::Request req;
	dnc::Web::GET g;
	dnc::Web::FORM form;

	putenv("QUERY_STRING=prename=Marvin&lastname=Smith");
	putenv("REQUEST_METHOD=GET");

	req.GetEnv();
	g = req.GetValues();

	h1.setText(new dnc::String(u8"ÜBASCHRIFD"));

	p.setText(new String("Hallo " + g["prename"] + g["lastname"]));

	form.Class(String("pollenstress"));
	form.Method(String("POST"));

	body.AddElement(&h1);
	body.AddElement(&p);
	body.AddElement(&form);
	html.AddElement(&body);

	std::cout << "Content-type:text/html\r\n\r\n";
	std::cout << html.toHtml().getStringValue();

}
