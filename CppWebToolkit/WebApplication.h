#pragma once
#ifndef WEBAPPLICATION_H
#define WEBAPPLICATION_H

#include "PageHolder.h"
#include "WebPage.h"
#include "DNC\String.h"
#include "DNC\Socket.h"

#include <vector>
#include <unordered_map>
#include <memory>
#include <utility>

namespace dnc {
	namespace Web {
		class WebApplication : public Object {
		public:
			WebApplication();
			~WebApplication();

			std::string ToString() override;
			std::string GetTypeString() override;

			template<typename T, typename = std::enable_if_t<std::is_base_of<WebPage, T>::value, T>>
			void registerPage(String name) {

				std::unique_ptr<PageHolder<T>> ptr = std::make_unique<PageHolder<T>>();

				pages.emplace(name.GetStringValue(), std::move(ptr));
			}

			void Start();

		private:
			// std::vector<std::unique_ptr<PageHolderBase>> pages;
			std::unordered_map<std::string, std::unique_ptr<PageHolderBase>> pages;

			void HandleReads(std::vector<Net::Sockets::Socket>& clientSockets, std::vector<Net::Sockets::Socket*> readSockets);
		};
	}
}

#endif // !WEBAPPLICATION_H