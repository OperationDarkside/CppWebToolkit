#pragma once
#include "String.h"
#include <map>

namespace dnc{
	namespace Web{

		class GET: public Object{
		public:
			GET();
			~GET();

			void setMap(std::map<std::string, std::string> m);

			String operator [](char* key);
			String operator [](std::string& key);
			String operator [](String& key);

		private:
			std::map<std::string, std::string> kv_map;
		};
	}
}