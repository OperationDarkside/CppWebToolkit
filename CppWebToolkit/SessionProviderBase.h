#pragma once

#ifndef SESSIONPROVIDERBASE_H
#define SESSIONPROVIDERBASE_H

#include "SessionBase.h"

#include <optional>

namespace dnc {
	namespace Web {
		template<typename Session, typename = std::enable_if_t<std::is_base_of<SessionBase, Session>::value, Session>>
		class SessionProviderBase {

			virtual const std::string& CreateSession () = 0;

			virtual const std::string& CreateSession (Session&& session) = 0;

			virtual std::optional<Session*> GetSession (const std::string& session_id) = 0;
		};
	}
}

#endif // !SESSIONPROVIDERBASE_H
