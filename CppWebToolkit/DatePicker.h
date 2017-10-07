#pragma once

#ifndef DATEPICKER_H
#define DATEPICKER_H

#include "Widget.h"
#include "Input.h"
#include "DNC\DateTime.h"

namespace dnc {
	namespace Web {
		class DatePicker : public Widget {
		public:
			DatePicker();
			DatePicker(DateTime _dt);
			~DatePicker();

			std::string ToString() override;
			std::string GetTypeString() override;

			DateTime& Date();
			void Date(DateTime& _dt);

			virtual String toHtml() override;
		private:
			DateTime dt;
			Input in;
		};
	}
}
#endif