#include "HttpPost.h"

namespace dnc {
	namespace Web {

		HttpPost::HttpPost () {}


		HttpPost::~HttpPost () {}

		bool HttpPost::isSet (std::string & key) {
			return parameters.find (key) != parameters.end ();
		}

		std::string & HttpPost::Field (std::string & key) {
			return parameters.at (key);
		}

		void HttpPost::Field (std::string key, std::string value) {
			parameters.insert ({key, value});
		}
	}
}