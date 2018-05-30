#include "MyFirstPage.h"

namespace dnc {
	namespace Web {

		MyFirstPage::MyFirstPage() {}


		MyFirstPage::~MyFirstPage() {}

		HttpResponse MyFirstPage::HandleRequest(HttpRequest & request) {
			HttpResponse resp;

			resp.ResponseCode (RESPONSE_CODE::OK_200);
			resp.Body (R"(<!DOCTYPE html>
						  <html>
						  <body>

						  <h1>My First Heading</h1>

						  <p>My first paragraph.</p>

						  </body>
						  </html>)");

			return resp;
		}

	}
}