cmake_minimum_required(VERSION 3.23)

add_library(nn
	src/tensor.cpp
)

target_include_directories(nn
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(nn PUBLIC cxx_std_20)

add_subdirectory(tests)
