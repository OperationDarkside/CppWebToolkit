#include "ThreadPool.h"

namespace dnc {
	namespace Web {
		ThreadPool::ThreadPool() {}

		ThreadPool::ThreadPool(std::function<void()> fun) {
			size_t threadnum = std::thread::hardware_concurrency();

			threads.reserve(threadnum);

			for(size_t i = 0; i < threadnum; ++i) {
				threads.push_back(std::thread(fun));
			}
		}

		ThreadPool::ThreadPool(std::function<void()> fun, size_t numberOfThreads) {
			
			threads.reserve(numberOfThreads);

			for(size_t i = 0; i < numberOfThreads; ++i) {
				threads.push_back(std::thread(fun));
			}
		}

		ThreadPool::~ThreadPool() {}

		/*void ThreadPool::Add(std::function<void()> fun) {
			threads.push_back(std::thread(fun));
		}*/

		size_t ThreadPool::Count() {
			return threads.size();
		}

		size_t ThreadPool::SupportedThreads() {
			return std::thread::hardware_concurrency();
		}

		void ThreadPool::Join() {
			for(auto& thr : threads) {
				thr.join();
			}
		}

	}
}