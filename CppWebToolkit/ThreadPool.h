#pragma once

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <vector>
#include <functional>

namespace dnc {
	namespace Web {
		class ThreadPool {
		public:
			ThreadPool();
			ThreadPool(ThreadPool& pool) = delete;
			ThreadPool(std::function<void()> fun);
			ThreadPool(std::function<void()> fun, size_t numberOfThreads);
			~ThreadPool();

			template <typename T>
			void Add(T* obj_ptr, std::function<void(T* obj)> fun) {
				threads.push_back(std::thread(fun, obj_ptr));
			}
			size_t Count();
			size_t SupportedThreads();
			void Join();

			ThreadPool& operator=(ThreadPool& pool) = delete;
		private:
			std::vector<std::thread> threads;
		};
	}
}

#endif