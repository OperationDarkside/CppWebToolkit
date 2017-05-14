#include "Ul.h"

namespace dnc{
	namespace Web{

		Ul::Ul(){}


		Ul::~Ul(){}
		std::string Ul::ToString(){
			return std::string("System.Web.Ul");
		}
		std::string Ul::getTypeString(){
			return std::string("Ul");
		}
	}
}