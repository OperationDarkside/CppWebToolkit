#include "A.h"

namespace dnc{
	namespace Web{

		A::A(){}


		A::~A(){}

		std::string A::ToString(){
			return std::string("System.Web.A");
		}

		std::string A::GetTypeString(){
			return std::string("A");
		}

		String A::Download(){
			return this->download;
		}

		void A::Download(String value){
			this->download = value;
		}

		String A::Href(){
			return this->href;
		}

		void A::Href(String value){
			this->href = value;
		}

		String A::HreafLang(){
			return this->hrefLang;
		}

		void A::HreafLang(String value){
			this->hrefLang = value;
		}

		String A::Media(){
			return this->media;
		}

		void A::Media(String value){
			this->media = value;
		}

		Relation A::Rel(){
			return this->rel;
		}

		void A::Rel(Relation value){
			this->rel = value;
		}

		Targets A::Target(){
			return this->target;
		}

		void A::Target(Targets value){
			this->target = value;
		}

		String A::Type(){
			return this->type;
		}

		void A::Type(String value){
			this->type = value;
		}

		String A::InnerText(){
			return this->innerText;
		}
		void A::InnerText(String value){
			this->innerText = value;
		}

		String A::getAttributeString(){
			String r;
			String targ;
			String res;

			res += HtmlElement::getAttributeString();

			if(this->download != ""){
				res += " download=\"" + this->download + "\" ";
			}
			if(this->href != ""){
				res += " href=\"" + this->href + "\" ";
			}
			if(this->hrefLang != ""){
				res += " hreflang=\"" + this->hrefLang + "\" ";
			}
			if(this->media != ""){
				res += " media=\"" + this->media + "\" ";
			}
			if(this->rel != Relation::None){
				switch(this->rel){
					case Relation::Alternate:
						r = "alternate";
						break;
					case Relation::Author:
						r = "author";
						break;
					case Relation::Bookmark:
						r = "bookmark";
						break;
					case Relation::External:
						r = "external";
						break;
					case Relation::Help:
						r = "help";
						break;
					case Relation::License:
						r = "license";
						break;
					case Relation::Next:
						r = "next";
						break;
					case Relation::NoFollow:
						r = "nofollow";
						break;
					case Relation::NoReferrer:
						r = "noreferrer";
						break;
					case Relation::NoOpener:
						r = "noopener";
						break;
					case Relation::Prev:
						r = "prev";
						break;
					case Relation::Search:
						r = "search";
						break;
					case Relation::Tag:
						r = "tag";
						break;
				}

				res += " target=\"" + r + "\" ";
			}
			if(this->target != Targets::None){
				switch(this->target){
					case Targets::Blank:
						targ = "_blank";
						break;
					case Targets::Parent:
						targ = "_parent";
						break;
					case Targets::Self:
						targ = "_self";
						break;
					case Targets::Top:
						targ = "_top";
						break;
				}

				res += " target=\"" + targ + "\" ";
			}
			if(this->type != ""){
				res += " type=\"" + this->type + "\" ";
			}

			return res;
		}
	}
}