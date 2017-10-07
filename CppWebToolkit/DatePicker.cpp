#include "DatePicker.h"
#include "DNC\Convert.h"

namespace dnc {
	namespace Web {

		DatePicker::DatePicker() {
			in.Type(InputType::Date);
		}

		DatePicker::DatePicker(DateTime _dt) : dt(_dt) {}

		DatePicker::~DatePicker() {}

		std::string DatePicker::ToString() {
			return std::string("System.Web.DatePicker");
		}

		std::string DatePicker::GetTypeString() {
			return std::string("DatePicker");
		}

		DateTime & DatePicker::Date() {
			return dt;
		}

		void DatePicker::Date(DateTime & _dt) {
			dt = _dt;
		}

		String DatePicker::toHtml() {
			// Year Bug
			String str(Convert::toString(dt.Year()).PadLeft(4, '0') + "-" + Convert::toString(dt.Month()).PadLeft(2, '0') + "-" + Convert::toString(dt.Day()).PadLeft(2, '0'));
			in.Value(str);
			this->AddElement(in);

			return Widget::toHtml();
		}

	}
}