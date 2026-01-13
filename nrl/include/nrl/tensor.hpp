#pragma once

#include <memory>
#include <iostream>
#include <utility>
#include <vector>

namespace nd::nrl {
	
	template<typename T>
	class  Tensor {
		protected:
			std::vector<T> m_data;
			std::vector<std::size_t> m_shape;
			std::vector<std::size_t> m_stride;
			
		public:
			Tensor(T t_data) : m_data{t_data}, m_shape{}, m_stride{} {};
			Tensor(std::vector<T> t_data) : m_data(t_data), m_shape{m_data.size()}, m_stride{1} {};
			Tensor(std::vector<std::vector<T>> t_data) : m_shape{t_data.size(), t_data[0].size()}, m_stride{t_data[0].size(), 1} {
				std::size_t num_of_columns = t_data[0].size();
				for(std::size_t i = 0; i < t_data.size(); i++ ) {
					if( t_data[i].size() != num_of_columns ) {
						throw std::invalid_argument("Dimension is inconsistent");
					}
				}
				for(std::size_t i = 0; i < t_data.size(); i++ ) {
					for(std::size_t j = 0; j < t_data[i].size(); j++ ) {
						m_data.push_back(t_data[i][j]);
					}
				}
			}

			const T& getItem() const {
				if(m_data.size() == 1) {
					return m_data[0];
				} else {
					throw std::runtime_error("getItem() can be called with tensor with single element");
				}
			}

			T& getItem() {	
				return const_cast<T&>(
						std::as_const(*this).getItem()
						);
			}


			const std::vector<std::size_t>& getStride() const { return m_stride; }
			std::vector<std::size_t>& getStride() { 
				return const_cast<std::vector<std::size_t>&>(
							std::as_const(*this).getStride()
						);
			};
			
			const std::vector<std::size_t>& getShape() const {
				return m_shape;
			}
			std::vector<std::size_t>& getShape() {
				return const_cast<std::vector<std::size_t>&>(
							std::as_const(*this).getShape()
						);
			}

			const T& operator()(std::size_t i) const {
				if(m_shape.size() == 0) {
					throw std::invalid_argument("Can't index scalar. Uset item().");
				}
				if(m_shape.size() == 1) {
					if(i >= m_shape[0]) {
						throw std::invalid_argument("Index" + std::to_string(i) + "out of bounds for array of size "+ std::to_string(m_shape[0]));
					}
					return m_data[i];
				}
				throw std::invalid_argument("This is 1D tensor. User two indicies for 2D tensor");
			}

			T& operator()(std::size_t i) {
				return const_cast<T&>(std::as_const(*this)(i));
			}

			const T& operator()(std::size_t i, std::size_t j) const {
				if(m_shape.size() == 2) {
					if(i >= m_shape[0]) {
						throw std::invalid_argument("Row index " + std::to_string(i)
							   + " is out of bounds for tenstor with " 
							   + std::to_string(m_shape[0]) + " rows.");
					}
					if(j >= m_shape[1] ) {
						throw std::invalid_argument("Column index " + std::to_string(j)
								+ " is out of bounds for tensor with"
								+ std::to_string(m_shape[1]) += " columns.");
					}
					std::size_t idx = i*m_stride[0] + j*m_stride[1];
					return m_data[idx];
				}
				throw std::invalid_argument("Need double argument for 2D tensor");
			}
			T& operator()(std::size_t i, std::size_t j) {
				return const_cast<T&>( std::as_const(*this)(i,j));
			}
			
			std::shared_ptr<Tensor<T>> operator+(const std::shared_ptr<Tensor<T>>& t) {
				//scalar + scalar
				if(m_shape.size() == 0 && t->m_shape.size() == 0) {
					T d = getItem() + t->getItem();
					return std::make_shared<Tensor<T>>(d);
				}
				//scalar + 1D
				if(m_shape.size() == 0 && t->m_shape.size() > 0) {
					T i = getItem();
					std::vector<T> result{};
					for(T d : t->m_data) {
						result.push_back( i + d );
					}
					return make_shared<Tensor<T>>(result);
				}
				if( getShape() == t->getShape() && m_shape.size()  == t->m_shape.size() ) {
					std::vector<std::vector<T>> result{};
					std::size_t j{0};
					std::vector<T> tmpv{};
					for(std::size_t i = 0; i<m_data.size(); i++) {
						T tmp = m_data[i] + t->m_data[i];
						if(j < m_stride[0]) {
							tmpv.push_back(tmp);
							j++;
						} else {
							result.push_back(std::vector<T>{tmpv});
							tmpv.clear();
							j=0;
						}
					}
					return std::make_shared<Tensor<T>>(result);
				}
				throw std::invalid_argument("shit");
			}

			friend std::ostream& operator<<(std::ostream& os, const Tensor& t) {
				std::string s = "[";
				if(t.getShape().size() == 0) {
					os << t.getItem();
					return os;
				} else if( t.getShape().size() == 1) {
					for(std::size_t i = 0; i < t.getShape()[0]; i++) {
						s += std::to_string( t.m_data[i] );
						if(i != t.getShape()[0] - 1) {
							s += ", ";
						}	
					}
				} else {
					for(std::size_t i=0; i<t.getShape()[0]; i++) {
						s += "[";
						for(std::size_t j=0; j<t.getShape()[1]; j++) {
							s += std::to_string(t(i,j));
							if(j!=t.getShape()[1]-1) {
								s += ", ";
							}
						}
						s += "]";
						if(i != t.getShape()[0]-1) {
							s += ", ";
						}
					}
				}
				s += "]";
				os << s;
				return os;
			}; 
	}; // template Tensor
	
}; // namespace nd::nrl
