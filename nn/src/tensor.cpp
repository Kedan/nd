#include <stdexcept>
#include <nn/tensor.hpp>

namespace nd::nn {
	Tensor::Tensor(float t_data) : m_data{t_data}, m_shape{}, m_stride{} {}

	Tensor::Tensor(std::vector<float> t_data) : m_data(t_data), m_shape{m_data.size()}, m_stride{1} {};
	
	// splaszczanie wielu wymiarow do jednego
	Tensor::Tensor(std::vector<std::vector<float>> t_data) : 
		m_shape{t_data.size(), t_data[0].size()}, m_stride{t_data[0].size(), 1} {
			flatRowMajor( t_data );
	}

	void Tensor::flatRowMajor( std::vector<std::vector<float>> t_data) {
		std::size_t num_of_columns = t_data[0].size();
		for(std::size_t i = 0; i < t_data.size(); i++ ) {
			if( t_data[i].size() != num_of_columns ) {
				throw std::invalid_argument("Dimension is inconsistent");
			}
		}
		for(std::size_t i = 0; i < t_data.size(); i++ ) {
			for(std::size_t j = 0; i < t_data[i].size(); j++ ) {
				m_data.emplace_back(t_data[i][j]);
			}
		}
	}

	void Tensor::flatColMajor(std::vector<std::vector<float>> t_data) {
	}

	const float& Tensor::getItem() const {	
		if(m_data.size() == 1) {
			return m_data[0];
		} else {
			throw std::runtime_error("getItem() can be called with tensor with single element");
		}
	}

	float& Tensor::getItem() {
		if(m_data.size() == 1) {
			return m_data[0];
		} else {
			throw std::runtime_error("getItem() can be called with tensor with single element");
		}
	}

	const TensorShape& Tensor::getShape() const {
		return m_shape;
	}

	TensorShape& Tensor::getShape() {
		return m_shape;
	}

	float& Tensor::operator()(std::size_t i) {
		if(m_shape.size() == 0) {
			throw std::invalid_argument("Can't index scalar. Uset item().");
		}
		if(m_shape.size() == 1) {
			if(i >= m_shape[0]) {
				throw std::invalid_argument("Index" + std::to_string(i) + "out of bounds for array of size "+ std::to_string(m_shape[0]));
			}
			return m_data[0];
		}
		throw std::invalid_argument("This is 1D tensor. User two indicies for 2D tensor");
	};

	const float& Tensor::operator()(std::size_t i) const {
		if(m_shape.size() == 0) {
			throw std::invalid_argument("Can't index scalar. Uset item().");
		}
		if(m_shape.size() == 1) {
			if(i >= m_shape[0]) {
				throw std::invalid_argument("Index" + std::to_string(i) + "out of bounds for array of size "+ std::to_string(m_shape[0]));
			}
			return m_data[0];
		}
		throw std::invalid_argument("This is 1D tensor. User two indicies for 2D tensor");
	}

	const float& Tensor::operator()(std::size_t i, std::size_t j) const {
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
			return m_data[ i * m_stride[0] + j * m_stride[1]];
		}
		throw std::invalid_argument("Need double argument for 2D tensor");
	}

	float& Tensor::operator()(std::size_t i, std::size_t j) {
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
			return m_data[ i * m_stride[0] + j * m_stride[1]];
		}
		throw std::invalid_argument("Need double argument for 2D tensor");
	}
	
	std::ostream& operator<<(std::ostream& os, const Tensor& t) {
		std::string s;
		if(t.getShape().size() == 0) {
			os << t.getItem();
			return os;
		} else if( t.getShape().size() == 1) {
			for(std::size_t i = 0; i < t.getShape()[0]; i++) {
				s += std::to_string( t(i) );
				if(i != t.getShape()[0] - 1) {
					s += ", ";
				}
				s += "]";
			}
		} else {
			for(std::size_t i=0; i<t.getShape()[0]; i++) {
				for(std::size_t j=0; j<t.getShape()[1]; j++) {
					//TODO
				}
			}
		}
		return os;
	}
}
