#pragma once

#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include "DNC\String.h"
#include "DNC\Socket.h"
#include <unordered_map>

namespace dnc {
	namespace Web {
		class HttpHeader {
		public:
			HttpHeader();
			~HttpHeader();

			void Parse(String& str);
			bool IsSet(String& key);
			String Field(String& fieldname);
			String& Method();
			String& Path();
			String& HttpVersion();

			Net::Sockets::Socket& Socket();
			void Socket(Net::Sockets::Socket socket);

		private:
			String method;
			String path;
			String http_version;
			std::unordered_map<std::string, std::string> fields;

			Net::Sockets::Socket sock;
		};
	}
}
#endif // !HTTPHEADER_H