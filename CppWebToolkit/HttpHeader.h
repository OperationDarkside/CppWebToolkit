#pragma once

#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include "DNC\String.h"
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

		private:
			String method;
			String path;
			String http_version;
			std::unordered_map<std::string, std::string> fields;

		};
	}
}
#endif // !HTTPHEADER_H