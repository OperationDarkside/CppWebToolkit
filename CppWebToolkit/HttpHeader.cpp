#include "HttpHeader.h"

namespace dnc {
	namespace Web {

		HttpHeader::HttpHeader() {}


		HttpHeader::~HttpHeader() {}

		void HttpHeader::Parse(String & str) {
			std::string s = str.GetStringValue();

			bool isFirstLine = true;
			bool isKey = true;
			bool isFirstColon = true;
			size_t len = s.size();
			std::string firstline;
			std::string key;
			std::string value;


			for(int i = 0; i < len; ++i) {
				char c = s[i];

				// if end is reached
				if((i + 1) == s.size()) {
					break;
				}

				// if end of headerline
				if(c == '\r' && s[i + 1] == '\n') {
					if(isFirstLine) {
						isFirstLine = false;
					} else {
						if(key != "") {
							fields.insert({key, value});
						} else {
							break;
						}
						key.clear();
						value.clear();
						isKey = true;
						isFirstColon = true;
					}
					i += 1;
					continue;
				}
				if(c == ':') {
					isKey = false;
					if(isFirstColon) {
						isFirstColon = false;
						++i;
						continue;
					}
				}
				if(isFirstLine) {
					firstline += c;
				} else {
					if(isKey) {
						key += c;
					} else {
						value += c;
					}
				}
			}

			unsigned char value_type = 0;
			
			for(char c : firstline) {
				if(c == ' ') {
					++value_type;
					continue;
				}
				switch(value_type) {
					case 0:
						method += c;
						break;
					case 1:
						path += c;
						break;
					case 2:
						http_version += c;
						break;
				}
			}
		}

		bool HttpHeader::IsSet(String & key) {
			return fields.find(key.GetStringValue()) != fields.end();
		}

		String & HttpHeader::Method() {
			return method;
		}

		String & HttpHeader::Path() {
			return path;
		}

		String & HttpHeader::HttpVersion() {
			return http_version;
		}

		String HttpHeader::Field(String & fieldname) {
			return String(fields.at(fieldname.GetStringValue()));
		}

	}
}