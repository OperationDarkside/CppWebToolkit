#pragma once
#ifndef SIMPLESESSIONPROVIDER_H
#define SIMPLESESSIONPROVIDER_H

#include "SessionProviderBase.h"
#include "SimpleSession.h"

#include <unordered_map>

namespace dnc {
	namespace Web {
		
		class SimpleSessionProvider : public SessionProviderBase<SimpleSession> {
		public:

			const std::string& CreateSession ();

			const std::string& CreateSession (SimpleSession&& session);

			std::optional<SimpleSession*> GetSession (const std::string& session_id);

		private:
			int next_session_id = 0;

			std::unordered_map<std::string, SimpleSession> sessions;
		};
	}
}
#endif // !SIMPLESESSIONPROVIDER_H