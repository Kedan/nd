#include <iostream>
#include <nrl/tensor.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	nd::nrl::Tensor<float> t{std::vector<float>{1.f,2.f,3.f,4.f,5.f}};
	std::vector<std::vector<float>> v {
	    {1.f, 2.f, 3.f},
	    {4.f, 5.f, 6.f},
	    {7.f, 8.f, 9.f}
	};
	nd::nrl::Tensor<float> d{v};
	std::cout << t << "\n";
	std::cout << "Boost test\n";
	std::cout << d << "\n";
	return 0;
}
