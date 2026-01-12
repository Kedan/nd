cmake_minimum_required(VERSION 3.23)

add_library(nrl
	src/tensor.cpp
	src/network.cpp
)

target_include_directories(nrl
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(nrl PUBLIC cxx_std_20)

add_subdirectory(tests)
