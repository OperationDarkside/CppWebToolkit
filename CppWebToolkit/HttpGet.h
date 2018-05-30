#pragma once

#ifndef HTTPGET_H
#define HTTPGET_H

#include <unordered_map>

namespace dnc {
	namespace Web {
		class HttpGet {
		public:
			HttpGet ();
			~HttpGet ();

			bool isSet (std::string& key);

			std::string& Field (std::string& key);
			void Field (std::string key, std::string value);

		private:
			std::unordered_map<std::string, std::string> parameters;
		};
	}
}

#endif // !HTTPGET_H