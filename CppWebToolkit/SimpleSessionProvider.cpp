#include "SimpleSessionProvider.h"

namespace dnc {
	namespace Web {

		const std::string & dnc::Web::SimpleSessionProvider::CreateSession () {
			int current_session_id = next_session_id++;
			std::string str_session_id = std::to_string (current_session_id);

			auto& session = sessions.emplace (str_session_id, SimpleSession());

			return session.first->first;
		}

		const std::string & SimpleSessionProvider::CreateSession (SimpleSession && session) {
			int current_session_id = next_session_id++;
			std::string str_session_id = std::to_string (current_session_id);

			auto& it_session = sessions.emplace (str_session_id, session);

			return it_session.first->first;
		}

		std::optional<SimpleSession*> dnc::Web::SimpleSessionProvider::GetSession (const std::string & session_id) {
			auto& found = sessions.find (session_id);
			if (found == sessions.end()) {
				return std::nullopt;
			}
			return &found->second;
		}
	}
}
