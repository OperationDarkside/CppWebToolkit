#pragma once
#ifndef SIMPLESESSION_H
#define SIMPLESESSION_H

#include "SessionBase.h"

#include <string>
#include <unordered_map>

namespace dnc {
	namespace Web {

		class SimpleSession : public SessionBase {
		public:
			SimpleSession ();
			~SimpleSession ();

			bool IsSet (const std::string& key);

			std::string& GetValue (const std::string& key);

			void Insert (std::string key, std::string value);

		private:
			std::unordered_map<std::string, std::string> values;
		};
	}
}

#endif // !SIMPLESESSION_H