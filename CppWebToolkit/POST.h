#pragma once

#ifndef POST_H
#define POST_H

#include "DNC/String.h"
#include <map>

namespace dnc{
	namespace Web{
		class POST : public Object{
		public:
			POST();
			~POST();

			std::string ToString() override;
			std::string GetTypeString() override;

			void setMap(std::map<std::string, std::string> m);

			String operator [](char* key);
			String operator [](std::string& key);
			String operator [](String& key);

		private:
			std::map<std::string, std::string> kv_map;
		};
	}
}
#endif