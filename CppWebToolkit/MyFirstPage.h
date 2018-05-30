#pragma once
#ifndef MYFIRSTPAGE_H
#define MYFIRSTPAGE_H

#include "WebPage.h"

namespace dnc {
	namespace Web {
		class MyFirstPage : public WebPage {
		public:
			MyFirstPage();
			~MyFirstPage();

			HttpResponse HandleRequest(HttpRequest& request) override;
		};
	}
}

#endif // !MYFIRSTPAGE_H