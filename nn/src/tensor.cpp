#include <nn/tensor.hpp>

namespace nd::nn {
	Tensor::Tensor(float t_data) : m_data{t_data}, m_size{} {}

	Tensor::Tensor(std::vector<float> t_data) : m_data(t_data), m_size{m_data.size()} {};
	
	// splaszczanie wielu wymiarow do jednego
	Tensor::Tensor(std::vector<std::vector<float>> t_data) {
	}
};
