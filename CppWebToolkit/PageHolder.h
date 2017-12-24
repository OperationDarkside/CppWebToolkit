#pragma once
#ifndef PAGEHOLDER_H
#define PAGEHOLDER_H

#include "PageHolderBase.h"
#include "WebPage.h"

namespace dnc {
	namespace Web {
		template<typename T>
		class PageHolder : public PageHolderBase {
		public:
			PageHolder();
			~PageHolder();

			std::string ToString() override;
			std::string GetTypeString() override;

			String getResponse(String& request) override;
		private:
			//Args&&... m_args;
		};

		template<typename T>
		inline PageHolder<T>::PageHolder() {}

		template<typename T>
		inline PageHolder<T>::~PageHolder() {}

		template<typename T>
		inline std::string PageHolder<T>::ToString() {
			return std::string("System.Web.PageHolder");
		}

		template<typename T>
		inline std::string PageHolder<T>::GetTypeString() {
			return std::string("PageHolder");
		}

		template<typename T>
		inline String PageHolder<T>::getResponse(String & request) {
			T instance;

			WebPage* wp = static_cast<WebPage*>(&instance);

			return wp->HandleRequest(request);
		}
	}
}

#endif // !PAGEHOLDER_H