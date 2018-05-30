#include "HttpGet.h"

namespace dnc {
	namespace Web {

		HttpGet::HttpGet () {}


		HttpGet::~HttpGet () {}

		bool HttpGet::isSet (std::string & key) {
			return parameters.find (key) != parameters.end ();
		}

		std::string & HttpGet::Field (std::string & key) {
			return parameters.at (key);
		}

		void HttpGet::Field (std::string key, std::string value) {
			parameters.insert ({key, value});
		}
	}
}