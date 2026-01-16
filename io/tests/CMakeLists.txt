cmake_minimum_required(VERSION 3.25)

set(LIB_NAME "io")

add_executable(${LIB_NAME}_test
)


target_link_libraries(${LIB_NAME}_test
	PRIVATE
		${LIB_NAME}
		gtest_main
)

target_include_directories(${LIB_NAME}_test
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME ${LIB_NAME}_test COMMAND ${LIB_NAME}_test)
