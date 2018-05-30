#pragma once
#ifndef HTTPPOST_H
#define HTTPPOST_H

#include <unordered_map>

namespace dnc {
	namespace Web {
		class HttpPost {
		public:
			HttpPost ();
			~HttpPost ();

			bool isSet (std::string& key);

			std::string& Field (std::string& key);
			void Field (std::string key, std::string value);

		private:
			std::unordered_map<std::string, std::string> parameters;
		};
	}
}

#endif // !HTTPPOST_H