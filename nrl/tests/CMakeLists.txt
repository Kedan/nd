cmake_minimum_required(VERSION 3.25)

add_executable(nrl_test
	src/tensor_test.cpp
)


target_link_libraries(nrl_test
	PRIVATE
		nrl
		gtest_main
)

target_include_directories(nrl_test
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME nrl_test COMMAND nrl_test)
