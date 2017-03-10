#pragma once

#include "HtmlElement.h"

class FORM : public HtmlElement {
public:
	FORM();
	~FORM();

	// AcceptCharset
	String& AcceptCharset();
	void AcceptCharset(String& value);
	// Action
	String& Action();
	void Action(String& value);
	// AutoComplete
	bool AutoComplete();
	void AutoComplete(bool value);
	// Enctype
	String& Enctype();
	void Enctype(String& value);
	// Method
	String& Method();
	void Method(String& value);
	// Name
	String& Name();
	void Name(String& value);
	// Novalidate
	bool Novalidate();
	void Novalidate(bool value);
	// Target
	String& Target();
	void Target(String& value);

	string toString();
	string getTypeString();
private:
	String acceptCharset;
	String action;
	int autocomplete;
	String enctype;
	String method;
	String name;
	bool novalidate;
	String target;

protected:
	String getAttributeString();
};

