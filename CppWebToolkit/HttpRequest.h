#pragma once

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <unordered_map>
#include <optional>

#include "DNC\Socket.h"
#include "PageHolderBase.h"

namespace dnc {
	namespace Web {

		enum class REQUEST_METHOD {
			HTTP_GET,
			HTTP_POST,
			HTTP_PUT,
			HTTP_DELETE
		};

		class HttpRequest {
		public:
			HttpRequest ();
			~HttpRequest ();

			REQUEST_METHOD& Method ();
			std::string& Resource ();
			std::string& Version ();
			std::optional<std::string> HeaderField (const std::string& fieldname);
			std::optional<std::string> GET (const std::string& fieldname);
			std::optional<std::string> POST (const std::string& fieldname);

			PageHolderBase* Page ();
			void Page (PageHolderBase* _page);

			Net::Sockets::Socket& Socket ();
			void Socket (Net::Sockets::Socket socket);

			void ParseGetFields ();
			bool Parse (const std::string& value);

		private:
			REQUEST_METHOD method;
			std::string resource;
			std::string get_str;
			std::string version;
			std::unordered_map<std::string, std::string> header_fields;
			std::unordered_map<std::string, std::string> get_fields;
			std::unordered_map<std::string, std::string> post_fields;

			PageHolderBase* page = nullptr;

			Net::Sockets::Socket sock;

			bool ParseFirstLine (const std::string& line);
			std::string UriDecode (const std::string & sSrc);
		};
	}
}
#endif // !HTTPREQUEST_H