#include <iostream>
#include "Html.h"
#include "Body.h"
#include "H1.h"
#include "Paragraph.h"
#include "Request.h"
#include "FORM.h"
#include "Response.h"
#include "DNC\String.h"

//using namespace dnc;
//using namespace dnc::Web;


int main(){
	dnc::Web::Html html;
	dnc::Web::Body body;
	dnc::Web::Paragraph p;
	dnc::Web::H1 h1;
	dnc::Web::Request req;
	dnc::Web::GET g;
	dnc::Web::Form form;
	dnc::Web::Response resp;

	putenv("QUERY_STRING=prename=Marvin&lastname=Smith");
	putenv("REQUEST_METHOD=GET");

	req.GetEnv();
	g = req.GetValues();

	h1.setText(new dnc::String(u8"ÜBASCHRIFD"));

	bool isPrename = false, isLastName = false;

	isPrename = g.isset("prename");
	isLastName = g.isset("lastname");

	if(isPrename && isLastName){
		p.setText(new dnc::String("Hallo " + g["prename"] + g["lastname"]));
	}

	form.Class(dnc::String("pollenstress"));
	form.Method(dnc::String("POST"));

	body.AddElement(&h1);
	body.AddElement(&p);
	body.AddElement(&form);
	html.AddElement(&body);

	resp.Html(html);
	resp.Send();
}
