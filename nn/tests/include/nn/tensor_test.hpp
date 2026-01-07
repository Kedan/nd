#pragma once
#include <memory>
#include <nn/tensor.hpp>
#include <gtest/gtest.h>

class TensorTest : public testing::Test {
	protected:
		std::string scalar_exception{"Can't index scalar. Uset item()."};
		std::vector<float> data{1.0f, 1.0f};
		std::shared_ptr<nd::nn::Tensor> t0{nullptr};
		std::shared_ptr<nd::nn::Tensor> t1{nullptr};

		std::size_t i{0};
	
		TensorTest() {
			t0 = std::make_shared<nd::nn::Tensor>(nd::nn::Tensor(1.0f));
			t1 = std::make_shared<nd::nn::Tensor>(nd::nn::Tensor(data));
		}
};
