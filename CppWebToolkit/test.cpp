#include <iostream>
#include <array>
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
#include "HtmlDataTable.h"
#include "TextBox.h"
#include "PasswordField.h"
#include "DatePicker.h"
#include "CheckBox.h"
#include "HorizontalLayout.h"
#include "VerticalLayout.h"
#include "GridLayout.h"
#include "WebApplication.h"
#include "MyFirstPage.h"
#include "SimpleSessionProvider.h"

//using namespace dnc;
//using namespace dnc::Web;


int main() {

	dnc::Web::WebApplication<dnc::Web::SimpleSession, dnc::Web::SimpleSessionProvider> app;
	app.registerPage<dnc::Web::MyFirstPage>(dnc::String("/"));
	app.Start();

	dnc::Web::Html html;
	dnc::Web::Head head;
	dnc::Web::Title title;
	dnc::Web::Meta meta;
	dnc::Web::Body body;
	//dnc::Web::Paragraph p;
	dnc::Web::H1 h1;
	dnc::Web::Request req;
	//dnc::Web::GET g;
	dnc::Web::Form form;
	dnc::Web::Response resp;

	//putenv("QUERY_STRING=prename=Marvin&lastname=Smith");
	//putenv("REQUEST_METHOD=GET");

	std::chrono::time_point<std::chrono::high_resolution_clock> t_construct = std::chrono::high_resolution_clock::now();

	req.GetEnv();
	//g = req.GetValues();

	//h1.InnerText(u8"�BASCHRIFD");

	bool isPrename = false, isLastName = false;

	//isPrename = g.isset("prename");
	//isLastName = g.isset("lastname");

	/*if(isPrename && isLastName){
		p.InnerText("Hallo " + g["prename"] + g["lastname"]);
	}*/

	//form.Class(dnc::String("pollenstress"));
	//form.Method(dnc::String("POST"));

	meta.CharSet(dnc::Web::CharSets::UTF8);
	title.SetText(dnc::String("Does this work?"));
	head.AddElement(title);
	head.AddElement(meta);
	
	body.AddElement(h1);
	//body.AddElement(p);

	{
		dnc::Web::Paragraph para;
		para.InnerText(dnc::String("Falala"));
		body.AddElement(para);
	}

	body.AddElement(form);

	// DATATABLE TEST
	dnc::Data::DataTable table2("dsfgdfg");
	table2.Columns().Add(dnc::Data::DataColumn("Vorname", dnc::Type::getType<dnc::String>(dnc::String())));

	dnc::Data::DataColumn col2("Nachname", dnc::Type::getType<dnc::String>(dnc::String()));
	table2.Columns().Add(col2);
	table2.Columns().Add(dnc::Data::DataColumn("Pisse", dnc::Type::getType<dnc::String>(dnc::String())));

	dnc::Data::DataRow row2 = table2.NewRow();
	row2.SetField<dnc::String>(0, dnc::String("Heinz"));
	row2.SetField<dnc::String>(1, dnc::String("Herrmann"));
	row2.SetField<dnc::String>(2, dnc::String("aus dem Arsch"));
	table2.Rows().Add(row2);

	dnc::Data::DataRow row3 = table2.NewRow();
	row3.SetField<dnc::String>(0, dnc::String("Peter"));
	row3.SetField<dnc::String>(1, dnc::String("Norbert"));
	row3.SetField<dnc::String>(2, dnc::String("Fehler"));
	table2.Rows().Add(row3);

	dnc::Web::HtmlDataTable htable;
	htable.FromDataTable(table2);
	body.AddElement(htable);

	dnc::Web::TextBox tb;
	tb.Text(dnc::String("Blasendropp"));
	body.AddElement(tb);

	dnc::Web::PasswordField pf;
	pf.Text(dnc::String("Lol"));
	body.AddElement(pf);

	dnc::Web::DatePicker dp;
	dp.Date(dnc::DateTime(2017,10,7));
	body.AddElement(dp);

	dnc::Web::CheckBox cb;
	cb.Checked(true);
	body.AddElement(cb);

	dnc::Web::HorizontalLayout hLayout;
	dnc::Web::TextBox tbBla1;
	dnc::Web::TextBox tbBla2;
	dnc::Web::TextBox tbBla3;
	dnc::Web::TextBox tbBla4;
	hLayout.AddWidget(tbBla1);
	hLayout.AddWidget(tbBla2);
	hLayout.AddWidget(tbBla3);
	hLayout.AddWidget(tbBla4);
	body.AddElement(hLayout);

	dnc::Web::VerticalLayout vLayout;
	vLayout.AddWidget(dnc::Web::TextBox());
	vLayout.AddWidget(dnc::Web::TextBox());
	vLayout.AddWidget(dnc::Web::TextBox());
	vLayout.AddWidget(dnc::Web::TextBox());
	body.AddElement(vLayout);
	

	dnc::Web::GridLayout grid;

	// COLUMN TEMPLATE
	std::vector<dnc::String> cols = {"20%", "auto"};
	grid.SetColumnTemplates(cols);

	// ROW TEMPLATE
	std::vector<dnc::String> rows = {"20%", "auto", "20%"};
	grid.SetRowTemplates(rows);

	// HEADER
	dnc::Web::H1 h;
	h.InnerText("Test Page");
	grid.AddWidget(h, 1, 1, 0, 3);

	// SIDE MENU
	dnc::Web::VerticalLayout menu;
	dnc::Web::Paragraph p;
	p.InnerText("Gaming");
	menu.AddWidget(p);
	p.InnerText("Programming");
	menu.AddWidget(p);
	p.InnerText("Affentheater");
	menu.AddWidget(p);
	p.InnerText("Videos");
	menu.AddWidget(p);
	grid.AddWidget(menu, 2, 1, 0, 0);

	// CENTER
	p.InnerText("Lorem IPSUM blablablabla");
	grid.AddWidget(p, 2, 2, 0, 2);

	// FOOTER
	p.InnerText("Does a footer have foot fetish?");
	grid.AddWidget(p, 3, 1, 0, 3);

	body.AddElement(grid);

	html.AddElement(head);
	html.AddElement(body);

	std::chrono::time_point<std::chrono::high_resolution_clock> t_render = std::chrono::high_resolution_clock::now();

	resp.Html(html);
	resp.Send();

	std::chrono::time_point<std::chrono::high_resolution_clock> t2 = std::chrono::high_resolution_clock::now();

	// Construction time
	std::chrono::microseconds diff = std::chrono::duration_cast<std::chrono::microseconds>(t_render - t_construct);
	std::cout << std::endl << diff.count() << '\n';

	// Render Time
	diff = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t_render);
	std::cout << std::endl << diff.count() << std::endl;

	//system("PAUSE");
}
