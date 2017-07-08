#include <iostream>
#include "Html.h"
#include "Body.h"
#include "H1.h"
#include "Paragraph.h"
#include "Request.h"
#include "FORM.h"
#include "Response.h"
#include "String.h"
#include "Head.h"
#include "Meta.h"
#include "Title.h"
#include "CharSets.h"
#include <chrono>

//using namespace dnc;
//using namespace dnc::Web;


int main(){
	dnc::Web::Html html;
	dnc::Web::Head head;
	dnc::Web::Title title;
	dnc::Web::Meta meta;
	dnc::Web::Body body;
	dnc::Web::Paragraph p;
	dnc::Web::H1 h1;
	dnc::Web::Request req;
	dnc::Web::GET g;
	dnc::Web::Form form;
	dnc::Web::Response resp;

	putenv("QUERY_STRING=prename=Marvin&lastname=Smith");
	putenv("REQUEST_METHOD=GET");

	std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();

	req.GetEnv();
	g = req.GetValues();

	h1.InnerText(u8"ÜBASCHRIFD");

	bool isPrename = false, isLastName = false;

	isPrename = g.isset("prename");
	isLastName = g.isset("lastname");

	if(isPrename && isLastName){
		p.InnerText("Hallo " + g["prename"] + g["lastname"]);
	}

	form.Class(dnc::String("pollenstress"));
	form.Method(dnc::String("POST"));

	meta.CharSet(dnc::Web::CharSets::UTF8);
	title.SetText(dnc::String("Does this work?"));
	head.AddElement(title);
	head.AddElement(meta);
	
	body.AddElement(h1);
	body.AddElement(p);

	{
		dnc::Web::Paragraph para;
		para.InnerText(dnc::String("Falala"));
		body.AddElement(para);
	}

	body.AddElement(form);

	html.AddElement(head);
	html.AddElement(body);

	resp.Html(html);
	resp.Send();

	std::chrono::time_point<std::chrono::system_clock> t2 = std::chrono::system_clock::now();

	std::chrono::microseconds diff = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	std::cout << std::endl << diff.count() << std::endl;
}
