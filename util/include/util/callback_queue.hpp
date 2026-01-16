#pragma once

#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <vector>
#include <algorithm>

namespace nd::util {
	template<typename TClass, typename... TCallbackParams> 
	class CallbackQueue final {
		private:
			using sptr		= std::shared_ptr<TClass>;
			using wptr		= std::weak_ptr<TClass>;
			using que 		= std::queue<std::weak_ptr<TClass>>;
			using callback 	= void(TClass::*)(TCallbackParams...);
		public:
			CallbackQueue( callback t_callback) : m_callback(t_callback) {} 
			
			void push( const sptr& t_object ) {
				std::lock_guard<std::mutex> lock( m_mutex );
				m_queue.push( wptr( t_object ));
			}

			void execute(TCallbackParams... t_params ){
				std::lock_guard<std::mutex> lock( m_mutex );
				if(m_callback) {
					while( !m_queue.empty() ) {
						if( auto ptr = m_queue.front().lock() ) {
							(ptr.get()->*m_callback)(t_params...);
						}
						m_queue.pop();
					}
				}
			};
		protected:
			callback m_callback; 
			que	m_queue;
			std::mutex m_mutex;
	};
}; // namespace nd::util
