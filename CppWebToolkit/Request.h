#pragma once
#include "GET.h"
#include "POST.h"
#include <map>

namespace dnc{
	namespace Web{
		class Request : public Object{
		public:
			Request();
			~Request();

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