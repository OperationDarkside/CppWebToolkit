#include "SimpleSession.h"

namespace dnc {
	namespace Web {

		SimpleSession::SimpleSession () {}


		SimpleSession::~SimpleSession () {}

		bool SimpleSession::IsSet (const std::string & key) {
			auto& found = values.find (key);
			if (found == values.end()) {
				return false;
			}
			return true;
		}

		std::string & SimpleSession::GetValue (const std::string & key) {
			auto& found = values.find (key);
			if (found == values.end ()) {
				return std::string();
			}
			return found->second;
		}

		void SimpleSession::Insert (std::string key, std::string value) {
			values.emplace (key, value);
		}

	}
}