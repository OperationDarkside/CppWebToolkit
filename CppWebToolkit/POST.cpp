#include "POST.h"
#include "DNC\String.h"

namespace dnc{
	namespace Web{

		POST::POST(){}

		POST::~POST(){}

		void POST::setMap(std::map<std::string, std::string> m){
			this->kv_map = m;
		}

		String POST::operator[](char * key){
			return String(&this->kv_map.at(std::string(key)));
		}

		String POST::operator[](std::string & key){
			return String(&this->kv_map.at(key));
		}

		String POST::operator[](String & key){
			return String(&this->kv_map.at(key.getStringValue()));
		}
	}
}