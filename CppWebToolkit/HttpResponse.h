#pragma once

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <unordered_map>

namespace dnc {
	namespace Web {

		enum class RESPONSE_CODE {
			OK_200,
			REDIRECT_301,
			NOT_FOUND_404,
			TEAPOT_418,
			ERROR_500
		};

		class HttpResponse {
		public:
			HttpResponse ();
			~HttpResponse ();

			RESPONSE_CODE ResponseCode ();
			void ResponseCode (RESPONSE_CODE code);

			std::string& Body ();
			void Body (std::string body);

			std::unordered_map<std::string, std::string>& HeaderFields ();

			std::string toSendString ();
		private:
			RESPONSE_CODE response_code = RESPONSE_CODE::OK_200;
			std::string version = "1.1";
			std::string body;
			std::unordered_map<std::string, std::string> header_fields;
		};

	}
}
#endif // !HTTPRESPONSE_H