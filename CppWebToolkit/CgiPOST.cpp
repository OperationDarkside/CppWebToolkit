#include "CgiPOST.h"

namespace dnc{
	namespace Web{

		CgiPOST::CgiPOST (){}

		CgiPOST::~CgiPOST (){}

		std::string CgiPOST::ToString() {
			return std::string("System.Web.Post");
		}

		std::string CgiPOST::GetTypeString() {
			return std::string("Post");
		}

		void CgiPOST::setMap(std::map<std::string, std::string> m){
			this->kv_map = m;
		}

		String CgiPOST::operator[](char * key){
			return String(this->kv_map.at(std::string(key)));
		}

		String CgiPOST::operator[](std::string & key){
			return String(this->kv_map.at(key));
		}

		String CgiPOST::operator[](String & key){
			return String(this->kv_map.at(key.GetStringValue()));
		}
	}
}