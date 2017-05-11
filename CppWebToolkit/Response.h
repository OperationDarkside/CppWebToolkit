#pragma once
#include "DNC/String.h"
#include "Html.h"
#include <iostream>

namespace dnc{
	namespace Web{

		class Response : public Object{
		public:
			Response();
			~Response();

			std::string ToString();
			std::string getTypeString();

			dnc::Web::Html Html();
			void Html(dnc::Web::Html value);

			void Send();

		private:
			dnc::Web::Html html;
		};
	}
}