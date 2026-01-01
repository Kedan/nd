cmake_minimum_required(VERSION 3.25)

add_library(bar 
	src/bar.cpp
)

target_include_directories(bar
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(bar PUBLIC cxx_std_20)

add_subdirectory(tests)
