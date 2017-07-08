#pragma once

#ifndef A_H
#define A_H

#include "HtmlElement.h"

namespace dnc{
	namespace Web{

		enum class Relation{
			None,
			Alternate,
			Author,
			Bookmark,
			External,
			Help,
			License,
			Next,
			NoFollow,
			NoReferrer,
			NoOpener,
			Prev,
			Search,
			Tag
		};

		enum class Targets{
			None,
			Blank,
			Parent,
			Self,
			Top
		};

		class A: public HtmlElement{
		public:
			A();
			~A();

			std::string ToString() override;
			std::string GetTypeString() override;

			// DOWNLOAD
			String Download();
			void Download(String value);

			// HREF
			String Href();
			void Href(String value);

			// HREFLANG
			String HreafLang();
			void HreafLang(String value);

			// MEDIA
			String Media();
			void Media(String value);

			// REL
			Relation Rel();
			void Rel(Relation value);

			// TARGET
			Targets Target();
			void Target(Targets value);

			// TYPE
			String Type();
			void Type(String value);

			// INNER TEXT
			String InnerText();
			void InnerText(String value);

		private:
			String download;
			String href;
			String hrefLang;
			String media;
			Relation rel;
			Targets target;
			String type;

			String getAttributeString() override;
		};


	}
}
#endif // !A_H