#pragma once
#include <vector>

namespace nd::nn {
	class Tensor {
		protected:
			std::vector<float> m_data;
			std::vector<std::size_t> m_shape;
		public:
			Tensor(float t_data:);
			Tensor(std::vector<float> t_data);
			Tensor(std::vector<std::vector<float>> t_data);
	};
};
