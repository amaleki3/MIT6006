cmake_minimum_required(VERSION 3.0)

project(Session2 CXX)
set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_library(utils_lib src/utils.cc)


add_executable(sess2 src/sess2.cc)
target_link_libraries(sess2 utils_lib)

enable_testing()
add_subdirectory(test)



