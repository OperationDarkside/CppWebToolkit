#pragma once

#ifndef RESPONSE_H
#define RESPONSE_H

#include "String.h"
#include "Html.h"
#include <iostream>

namespace dnc{
	namespace Web{

		class Response : public Object{
		public:
			Response();
			~Response();

			std::string ToString() override;
			std::string GetTypeString() override;

			dnc::Web::Html Html();
			void Html(dnc::Web::Html value);

			void Send();

		private:
			dnc::Web::Html html;
		};
	}
}
#endif