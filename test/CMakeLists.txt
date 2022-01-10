cmake_minimum_required(VERSION 3.12)
project(sv-time-tester)

FILE(GLOB_RECURSE FILE_SOURCES "*.cpp")
FILE(GLOB_RECURSE FILE_HEADERS "*.hpp")

add_executable(${PROJECT_NAME}
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)
target_link_libraries(${PROJECT_NAME} "sv-time")