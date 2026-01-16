/*
 * Qsin<T> – Quasi Singleton.
 *
 * Provides a global instance of T.
 * If T has a private/protected constructor and declares Qsin<T> as friend,
 * then Qsin<T>::getInstance() acts as a true singleton.
 *
 * Otherwise, local instances of T are also possible.
 */

#pragma once

#include <memory>
#include <mutex>

namespace ns::util {
	template<typename T>
	class QuasiSingleton {
		protected:
			QuasiSingleton() = default;
			virtual ~QuasiSingleton() = default;
			QuasiSingleton(const QuasiSingleton&) = delete;
			QuasiSingleton& operator=(const QuasiSingleton&) = delete;
			QuasiSingleton(const QuasiSingleton&&) = delete;
			QuasiSingleton& operator=(const QuasiSingleton&&) = delete;
		public:
			static T& getInstance() {
				static std::unique_ptr<T> instance;
				static std::once_flag flag;
				std::call_once(flag, []{
					instance.reset(new T());
				});
				return *instance;
			}
	};
}
