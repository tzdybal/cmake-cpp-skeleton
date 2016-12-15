cmake_minimum_required(VERSION 2.8.2)

project(cmake-cpp-skeleton)

set (CMAKE_CXX_STANDARD 14)

################################################################################
### TESTS
################################################################################

# Fetch GoogleTest from github and use it as subdirectory for convenience 
# inspired by https://crascit.com/2015/07/25/cmake-gtest/
configure_file(googletest.CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(
	${CMAKE_BINARY_DIR}/googletest-src 
	${CMAKE_BINARY_DIR}/googletest-build
)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories(
		"${gtest_SOURCE_DIR}/include"
		"${gmock_SOURCE_DIR}/include"
	)
endif()

# compile 
add_executable(test_runner test_runner.cpp)
target_link_libraries(test_runner gtest gtest_main gmock gmock_main)

# add 'make test' functionality
enable_testing()
add_test(NAME google-tests COMMAND test_runner)

