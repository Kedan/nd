#pragma once
#include <memory>
#include <nrl/tensor.hpp>
#include <gtest/gtest.h>

class TensorGetter : public nd::nrl::Tensor<float> {
	public:
		std::vector<float> getFlatternData() const;
};

class TensorTest : public testing::Test {
	public:
		using Tensor = nd::nrl::Tensor<float>;
	protected:
		std::string scalar_exception{"Can't index scalar. Uset item()."};
		std::vector<float> data{1.0f, 1.0f};
		std::vector<std::vector<float>> data2d{{1,2,3},{4,5,6},{7,8,9}};
		std::vector<std::vector<float>> data2d_invalid{{1,2,3},{4,5,6},{7,8,9,0}};
		std::shared_ptr<Tensor> t0{nullptr};
		std::shared_ptr<Tensor> t1{nullptr};
		std::shared_ptr<Tensor> t2{nullptr};

		std::size_t i{0};
	
		TensorTest() {
			t0 = std::make_shared<Tensor>(Tensor(1.0f));
			t1 = std::make_shared<Tensor>(Tensor(data));
		}
};
