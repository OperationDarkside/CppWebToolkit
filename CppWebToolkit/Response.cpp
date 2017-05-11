#include "Response.h"

namespace dnc{
	namespace Web{

		Response::Response(){}


		Response::~Response(){}
		std::string Response::ToString(){
			return std::string("System.Web.Response");
		}
		std::string Response::getTypeString(){
			return std::string("Response");
		}
		dnc::Web::Html Response::Html(){
			return this->html;
		}
		void Response::Html(dnc::Web::Html value){
			this->html = value;
		}


		void Response::Send(){
			std::cout << "Content-type:text/html\r\n\r\n";
			std::cout << this->html.toHtml().getStringValue();
		}
	}
}