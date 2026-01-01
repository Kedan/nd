cmake_minimum_required(VERSION 3.23)

add_executable(unit_tests
	src/my_test.cpp
)

target_link_libraries(
	unit_tests
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
