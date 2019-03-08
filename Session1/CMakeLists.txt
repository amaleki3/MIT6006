cmake_minimum_required(VERSION 3.0)

project(Session1 CXX)
set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_library(peakfinder_lib src/peak_finder.cc)


add_executable(sess1 src/sess1.cc)
target_link_libraries(sess1 peakfinder_lib)

enable_testing()
add_subdirectory(test)



