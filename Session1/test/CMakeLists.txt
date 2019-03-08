cmake_minimum_required(VERSION 3.0)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(Sess1Test sess1_test.cc)
target_link_libraries(Sess1Test ${GTEST_LIBRARIES} 
																pthread
																peakfinder_lib)


add_test(NAME sess1_test COMMAND Sess1Test)
#gtest_add_tests(TARGETS runTests TEST_PREFIX AUTO)
#gtest_add_tests(TARGET      runTests
#                TEST_SUFFIX .withArgs
#                TEST_LIST   withArgsTests)