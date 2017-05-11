#pragma once
#include "DNC/String.h"
#include <map>


namespace dnc{
	namespace Web{

		class GET: public Object{

			friend class Request;

		public:
			GET();
			~GET();

			bool isset(String key);

			String operator[](char* key);
			String operator[](std::string& key);
			String operator[](String& key);

		private:
			std::map<std::string, std::string> kv_map;

			void setMap(std::map<std::string, std::string> m);
		};
	}
}