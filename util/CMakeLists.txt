cmake_minimum_required(VERSION 3.23)

set(LIB_NAME "util")

add_library(${LIB_NAME}
	src/cli_parser.cpp
)

target_include_directories(${LIB_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../ext
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)

#add_subdirectory(tests)
