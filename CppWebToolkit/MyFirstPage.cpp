#include "MyFirstPage.h"

namespace dnc {
	namespace Web {

		MyFirstPage::MyFirstPage() {}


		MyFirstPage::~MyFirstPage() {}

		HttpResponse<SimpleSession> MyFirstPage::HandleRequest(HttpRequest<SimpleSession> & request) {
			HttpResponse<SimpleSession> resp;

			std::string body = R"(<!DOCTYPE html>
						  <html>
						  <body>

						  <h1>My First Heading</h1>

						  <p>My first paragraph.</p>)";

			if (request.HasSession () && request.CurrentSession ()->IsSet("name")) {
				std::string name = request.CurrentSession ()->GetValue ("name");

				body += "<p><strong>Name</strong>: " + name + "</p>";
			}

			body += "</body></html>";

			resp.ResponseCode (RESPONSE_CODE::OK_200);
			resp.Body (body);

			if (!request.HasSession ()) {
				SimpleSession& session = resp.CreateSession ();
				session.Insert ("name", "Chuck Norris");
			}

			return resp;
		}

	}
}