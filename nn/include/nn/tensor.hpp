#pragma once
#include <iostream>
#include <vector>

namespace nd::nn {
	
	using TensorShape = std::vector<std::size_t>;

	class Tensor {
		protected:
			std::vector<float> m_data;
			TensorShape m_shape;
			TensorShape m_stride;
			
			void flatRowMajor(std::vector<std::vector<float>> t_data);
			void flatColMajor(std::vector<std::vector<float>> t_data);
		public:
			Tensor(float t_data);
			Tensor(std::vector<float> t_data);
			Tensor(std::vector<std::vector<float>> t_data);

			const float& getItem() const;
			float& getItem();
			
			const TensorShape& getShape() const;

			const float& operator()(std::size_t i) const;
			float& operator()(std::size_t i);

			const float& operator()(std::size_t i, std::size_t j) const;
			float& operator()(std::size_t i, std::size_t j);

	};
	
	std::ostream& operator<<(std::ostream& os, const Tensor& t); 
};
