cmake_minimum_required(VERSION 3.25)

add_executable(foo_test
	src/foo_test.cpp
)


target_link_libraries(foo_test
	PRIVATE
		foo
		gtest_main
)

target_include_directories(foo_test
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME foo_test COMMAND foo_test)
