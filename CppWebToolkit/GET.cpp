#pragma once
#include "GET.h"

namespace dnc{
	namespace Web{
		GET::GET(){}


		GET::~GET(){}

		std::string GET::ToString() {
			return std::string("System.Web.Get");
		}

		std::string GET::GetTypeString() {
			return std::string("Get");
		}

		bool GET::isset(String key){
			bool res = false;
			std::map<std::string, std::string>::iterator it;

			it = this->kv_map.find(key.GetStringValue());

			return it != this->kv_map.end();
		}

		void GET::setMap(std::map<std::string, std::string> m){
			this->kv_map = m;
		}

		String GET::operator[](char * key){
			return String(&this->kv_map.at(std::string(key)));
		}

		String GET::operator[](std::string & key){
			return String(&this->kv_map.at(key));
		}

		String GET::operator[](String & key){
			return String(&this->kv_map.at(key.GetStringValue()));
		}
	}
}