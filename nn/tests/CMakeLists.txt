cmake_minimum_required(VERSION 3.25)

add_executable(nn_test
	src/tensor_test.cpp
)


target_link_libraries(nn_test
	PRIVATE
		nn
		gtest_main
)

target_include_directories(nn_test
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME nn_test COMMAND nn_test)
