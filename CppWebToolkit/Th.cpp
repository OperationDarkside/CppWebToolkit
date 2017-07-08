#include "Th.h"

namespace dnc {
	namespace Web {

		Th::Th() {
			this->html_part1 = new String("<th>");
			this->html_part2 = new String("</th>");
		}

		Th::~Th() {}

		std::string dnc::Web::Th::ToString() {
			return std::string("System.Web.Th");
		}

		std::string dnc::Web::Th::GetTypeString() {
			return std::string("Th");
		}

		String Th::Abbr() {
			return this->abbr;
		}

		void Th::Abbr(String value) {
			this->abbr = value;
		}

		int Th::ColSpan() {
			return this->colspan;
		}

		void Th::ColSpan(int value) {
			this->colspan = value;
		}

		String Th::Headers() {
			return this->headers;
		}

		void Th::Headers(String value) {
			this->headers = value;
		}

		int Th::RowSpan() {
			return this->rowspan;
		}

		void Th::RowSpan(int value) {
			this->rowspan = value;
		}

		Th_Scope Th::Scope() {
			return this->scope;
		}

		void Th::Scope(Th_Scope value) {
			this->scope = value;
		}

		String Th::getAttributeString() {
			String res;
			String scp;

			res += HtmlElement::getAttributeString();

			if(this->abbr != "") {
				res += " abbr=\"" + this->abbr + "\" ";
			}

			if(this->colspan != -1) {
				res += " colspan=\"" + std::to_string(this->colspan) + "\" ";
			}

			if(this->headers != "") {
				res += " headers=\"" + this->headers + "\" ";
			}

			if(this->rowspan != -1) {
				res += " rowspan=\"" + std::to_string(this->rowspan) + "\" ";
			}

			if(this->scope != Th_Scope::None) {
				switch(this->scope) {
					case Th_Scope::Col:
						scp = "col";
						break;
					case Th_Scope::ColGroup:
						scp = "colgroup";
						break;
					case Th_Scope::Row:
						scp = "row";
						break;
					case Th_Scope::RowGroup:
						scp = "rowgroup";
						break;
				}
				res += " scope=\"" + scp + "\" ";
			}

			return res;
		}

	}
}