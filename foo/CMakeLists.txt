cmake_minimum_required(VERSION 3.23)

add_library(foo
	src/foo.cpp
)

target_include_directories(foo
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(foo PUBLIC cxx_std_20)

add_subdirectory(tests)
