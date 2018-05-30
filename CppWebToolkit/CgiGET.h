#pragma once

#ifndef GET_H
#define GET_H

#include "DNC/String.h"
#include <map>


namespace dnc{
	namespace Web{

		class CgiGET: public Object{

			friend class Request;

		public:
			CgiGET ();
			~CgiGET ();

			std::string ToString() override;
			std::string GetTypeString() override;

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
#endif