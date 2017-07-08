#pragma once

#ifndef REQUEST_H
#define REQUEST_H

#include "GET.h"
#include "POST.h"
#include "DNC/List.h"
#include <map>

namespace dnc{
	namespace Web{
		class Request : public Object{
		public:
			Request();
			~Request();

			std::string ToString() override;
			std::string GetTypeString() override;

			void GetEnv();

			GET GetValues();
			POST PostValues();

		private:
			std::string UriDecode(const std::string& sSrc);

			std::map<std::string, std::string> get_kvs;
			std::map<std::string, std::string> post_kvs;
		};
	}
}
#endif