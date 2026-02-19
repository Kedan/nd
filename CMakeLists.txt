cmake_minimum_required(VERSION 3.23)
project(nudny VERSION 0.1.0 DESCRIPTION "CORE-90 Nudny Software")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS, " -Wall -Wextra -Wpedantic")
set(SANITIZER_FLAGS, "")
add_custom_target(coverage
	COMMAND ${CMAKE_CTEST_COMMAND} -V --preset coverage
	COMMAND ${CMAKE_SOURCE_DIR}/scripts/gencov.sh ${CMAKE_BINARY_DIR}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMENT "Running test and generating coverage raport"
)
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(nd
	src/main.cpp
)


include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/ext/nlohmann/include
)
target_include_directories(nd
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(nd
	PRIVATE
		util
		io
		nrl	
)
option(RELEASE "Relese" OFF)
if(RELEASE)
	message(STATUS "==== Build release version ====")
	add_compile_options(-g -O3 -DNDEBIG)
endif()
option(ENABLE_COVERAGE "Enable coverage" OFF)
if(ENABLE_COVERAGE)
	message(STATUS "Coverage enabled")
	add_compile_options(--coverage -O0 -g)
	add_link_options(--coverage)
endif()
option(ENABLE_VALGRIND "Enable Valgrind" OFF)
option(ENABLE_SANITIZERS "Enable ASan + UBSan" OFF)
if(ENABLE_SANITIZERS)
	message("Sanitazers ENABLED")
	set(SANITAZER_FLAG
		-fsanitize=address,undefined
		-fno-omit-frame-pointer
		-g
	)
	add_compile_options(${SANITAZER_FLAGS} -D_GLIBCXX_ASSERTIONS)
	add_link_options(${SANITAZER_FLAGS})
endif()

#add_subdirectory(foo)
#add_subdirectory(bar)

add_subdirectory(util)
add_subdirectory(io)
add_subdirectory(nrl)
add_subdirectory(tests)

add_library(nudny STATIC src/main.cpp)
target_link_libraries(nudny
	PUBLIC
	util
	io
	nrl
)
add_library(nudny::silnik ALIAS nudny)
