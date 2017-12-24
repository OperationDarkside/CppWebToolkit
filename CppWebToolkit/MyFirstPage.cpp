#include "MyFirstPage.h"

namespace dnc {
	namespace Web {

		MyFirstPage::MyFirstPage() {}


		MyFirstPage::~MyFirstPage() {}

		String MyFirstPage::HandleRequest(String & request) {
			return String(R"(<!DOCTYPE html>
						  <html>
						  <body>

						  <h1>My First Heading</h1>

						  <p>My first paragraph.</p>

						  </body>
						  </html>)");
		}

	}
}