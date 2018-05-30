#pragma once
#include "CgiGET.h"

namespace dnc{
	namespace Web{
		CgiGET::CgiGET (){}


		CgiGET::~CgiGET (){}

		std::string CgiGET::ToString() {
			return std::string("System.Web.Get");
		}

		std::string CgiGET::GetTypeString() {
			return std::string("Get");
		}

		bool CgiGET::isset(String key){
			bool res = false;
			std::map<std::string, std::string>::iterator it;

			it = this->kv_map.find(key.GetStringValue());

			return it != this->kv_map.end();
		}

		void CgiGET::setMap(std::map<std::string, std::string> m){
			this->kv_map = m;
		}

		String CgiGET::operator[](char * key){
			return String(this->kv_map.at(std::string(key)));
		}

		String CgiGET::operator[](std::string & key){
			return String(this->kv_map.at(key));
		}

		String CgiGET::operator[](String & key){
			return String(this->kv_map.at(key.GetStringValue()));
		}
	}
}