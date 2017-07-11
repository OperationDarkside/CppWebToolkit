#include "Td.h"

namespace dnc {
	namespace Web {

		Td::Td() {
			this->html_part1 = new String("<td>");
			this->html_part2 = new String("</td>");
		}

		Td::~Td() {}

		std::string dnc::Web::Td::ToString() {
			return std::string("System.Web.Td");
		}

		std::string dnc::Web::Td::GetTypeString() {
			return std::string("Td");
		}

		int Td::ColSpan() {
			return this->colspan;
		}

		void Td::ColSpan(int value) {
			this->colspan = value;
		}

		String Td::Headers() {
			return this->headers;
		}

		void Td::Headers(String value) {
			this->headers = value;
		}

		String Td::InnerText() {
			return this->innerText;
		}

		void Td::InnerText(String value) {
			this->innerText = value;
		}

		int Td::RowSpan() {
			return this->rowspan;
		}

		void Td::RowSpan(int value) {
			this->rowspan = value;
		}

		String Td::getAttributeString() {
			String res;

			res += HtmlElement::getAttributeString();

			if(this->colspan != -1) {
				res += " colspan=\"" + std::to_string(this->colspan) + "\" ";
			}

			if(this->headers != "") {
				res += " headers=\"" + this->headers + "\" ";
			}

			if(this->rowspan != -1) {
				res += " rowspan=\"" + std::to_string(this->rowspan) + "\" ";
			}

			return res;
		}

	}
}