cmake_minimum_required(VERSION 3.0)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(Sess2Test sess2_test.cc)
target_link_libraries(Sess2Test ${GTEST_LIBRARIES} 
																pthread
																utils_lib)


add_test(NAME sess2_test COMMAND Sess2Test)
#gtest_add_tests(TARGETS runTests TEST_PREFIX AUTO)
#gtest_add_tests(TARGET      runTests
#                TEST_SUFFIX .withArgs
#                TEST_LIST   withArgsTests)