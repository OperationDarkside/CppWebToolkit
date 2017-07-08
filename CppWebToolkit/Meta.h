#pragma once

#ifndef META_H
#define META_H

#include "HtmlElement.h"
#include "CharSets.h"

namespace dnc{
	namespace Web{

		class Meta: public HtmlElement{
		public:
			Meta();
			~Meta();

			std::string ToString() override;
			std::string GetTypeString() override;

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

			virtual String getAttributeString() override;
		};
	}
}
#endif