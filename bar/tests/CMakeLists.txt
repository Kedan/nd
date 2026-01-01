cmake_minimum_required(VERSION 3.23)

add_executable(bar_test
	src/bar_test.cpp
)

target_include_directories(bar_test
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(bar_test
	bar
	gtest_main
)

add_test(NAME bar_test COMMAND bar_test)
