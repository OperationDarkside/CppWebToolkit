#include "POST.h"

namespace dnc{
	namespace Web{

		POST::POST(){}

		POST::~POST(){}

		std::string POST::ToString() {
			return std::string("System.Web.Post");
		}

		std::string POST::GetTypeString() {
			return std::string("Post");
		}

		void POST::setMap(std::map<std::string, std::string> m){
			this->kv_map = m;
		}

		String POST::operator[](char * key){
			return String(this->kv_map.at(std::string(key)));
		}

		String POST::operator[](std::string & key){
			return String(this->kv_map.at(key));
		}

		String POST::operator[](String & key){
			return String(this->kv_map.at(key.GetStringValue()));
		}
	}
}