cmake_minimum_required(VERSION 3.12)

project(sv-time VERSION 1.0.0)

option(BUILD_TESTER "Build tester" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)

if(BUILD_TESTER)
  add_subdirectory(test)
endif()