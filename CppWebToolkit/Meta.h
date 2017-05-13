#pragma once
#include "HtmlElement.h"
#include "CharSets.h"

namespace dnc{
	namespace Web{

		class Meta: public HtmlElement{
		public:
			Meta();
			~Meta();

			std::string ToString();
			std::string getTypeString();

			// CHARSET
			CharSets CharSet();
			void CharSet(CharSets value);

			// CONTENT
			String Content();
			void Content(String value);

			// HTTP EQUIV
			String HttpEquiv();
			void HttpEquiv(String value);

			// NAME
			String Name();
			void Name(String value);
		private:
			CharSets charset;
			String content;
			String httpEquiv;
			String name;

			String getAttributeString() override;
		};
	}
}