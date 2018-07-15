#pragma once
#ifndef MYFIRSTPAGE_H
#define MYFIRSTPAGE_H

#include "WebPage.h"
#include "SimpleSession.h"

namespace dnc {
	namespace Web {
		class MyFirstPage : public WebPage<SimpleSession> {
		public:
			MyFirstPage();
			~MyFirstPage();

			HttpResponse<SimpleSession> HandleRequest(HttpRequest<SimpleSession>& request) override;
		};
	}
}

#endif // !MYFIRSTPAGE_H