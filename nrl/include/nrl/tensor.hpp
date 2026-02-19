#pragma once

#include <vector>
#include <mdspan>

namespace nd::nrl {
	template<typename T>
	class tensor {
		protected:
			std::vector<T> m_data;
			auto m_span = std::mdspan();

			std::vector<std::size_t> m_shape;
			std::vector<std::size_t> m_stride;

			void setShapeAndStride() {
				if(!isScalar()) {
					for(std::size_t i=0; i<m_span.rank(); ++i) {
						m_shape.push_back(m_span.extent(i));
						m_stride.push_back(m_span.mapping().stride(i));
					}
				}
			}

			tensor(std::vector<T> t_data, std::mdspan t_span) : m_data(t_data), m_span{t_span} {
					setShapeAndStride();
				}	
		public:
			tensor() = default;
			tensor(const tensor<T>& t) : m_data{t.m_data}, m_span{t.m_span}, m_shape{t.m_shape}, m_stride{t.m_stride} {}
			tensor(T t_data) : m_data{t_data}, m_shape{}, m_stride{} {};
			tensor(std::vector<T> t_data) : m_data(t_data), m_span{m_data.data(),m_data.size()} {
				setShapeAndStride();
			}
			tensor(std::vector<T> t_data, std::size_t... t_shape) : m_data(t_data), m_span{m_data.data(), t_shape} {
				setShapeAndStride();
			};

			inline std::size_t dimension() { return m_span.rank(); }
			inline bool isScalar() { return m_data.size() == 1; }
			
			T& item() {};
			std::vector<std::size_t> shape(){
				return m_shape;
			};
			std::vector<std::size_t> stride(){
				return m_stride;
			};
			T& operator()(std::size_t... idx) {
				if(sizeof...(idx) == m_span.rank()) {
					return m_span(idx...);
				}
				throw std::invalid_argument("tensor has " + std::to_string(m_span.rank()) + " dimension");
			};
			std::shared_ptr<tensor<T>> operator+(const std::shared_ptr<tensor<T>>& t) {
				if(isScalar() && t->isScalar()) {
					return std::make_shared<tensor<T>>(item() + t->item())
				}
				if(dimension()==1 && t->dimension()>1) {
					std::vector<T> r;
					for(T& elem : t->m_data) {
						r.push_back( item() + elem );
					}
					return std::make_shared<tensor<T>>(r);
				}
				if(m_span == t->m_span) {
					//TODO	
				}	
			}

			std::shared_ptr<tensor<T>> operator+(T& t) {
				if(isScalar()) {
					return std::make_shared<tensor<T>>(t+m_data[0]);
				} 
				std::vector<T> result;
				for(T& m_t : m_data) {
					result.push_back(m_t + t);
				}
				return std::make_shared<tensor<T>>(result, m_span);
			}

			std::shared_ptr<tensor<T>> operator*(const std::shared_ptr<tensor<T>>&) {}
			std::shared_ptr<tensor<T> >operator*(T&) {};

			friend std::ostream& operator<<(std::ostream& os, const tensor& t) {}
			friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<tensor<T>>& t) {
				return os << (*t);
			}
	}; // template tensor;
}; // namespace nd::nrl
