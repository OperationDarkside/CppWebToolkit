#include "HttpResponse.h"

namespace dnc {
	namespace Web {

		HttpResponse::HttpResponse () {}


		HttpResponse::~HttpResponse () {}

		RESPONSE_CODE dnc::Web::HttpResponse::ResponseCode () {
			return response_code;
		}

		void dnc::Web::HttpResponse::ResponseCode (RESPONSE_CODE code) {
			response_code = code;
		}

		std::string & dnc::Web::HttpResponse::Body () {
			return body;
		}

		void dnc::Web::HttpResponse::Body (std::string body) {
			this->body = body;
		}

		std::unordered_map<std::string, std::string>& HttpResponse::HeaderFields () {
			return header_fields;
		}

		std::string HttpResponse::toSendString () {
			std::string res = "HTTP/" + version;

			switch (response_code) {
			case RESPONSE_CODE::OK_200:
				res += " 200 OK";
				break;
			case RESPONSE_CODE::NOT_FOUND_404:
				res += " 404 Not Found";
				break;
			}
			res += "\r\n";

			if (header_fields.size() > 0) {
				for (auto field : header_fields) {
					res += field.first + ':' + field.second + "\r\n";
				}
				res.erase (res.length() - 2);
			}

			res += "\r\n\r\n" + body;

			return res;
		}

	}
}