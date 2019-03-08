#include <iostream>
#include <gtest/gtest.h>

#include "basic_algorithms/peak_finder.h"

TEST(peak_finder, Test1){
	int array[kSize] = 
	  {1, 2, 3, 4, 5, 6, 8, 10, 11 , 13};
	ASSERT_EQ(13, PeakFinder1DSlow(array));
}

TEST(peak_finder, Test2){
	int array[kSize] = 
	  {1, 2, 3, 4, 15, 6, 8, 10, 11 , 13};
	ASSERT_EQ(15, PeakFinder1DSlow(array));
}

TEST(peak_finder, Test3){
	int array[kSize] = 
	  {11, 2, 3, 4, 5, 6, 8, 10, 11 , 13};
	ASSERT_EQ(11, PeakFinder1DSlow(array));
}

TEST(peak_finder, Test4){
	int array[kSize] = 
	  {1, 2, 3, 4, 5, 6, 8, 10, 11 , 13};
	ASSERT_EQ(13, PeakFinder1DFast(array));
}

TEST(peak_finder, Test5){
	int array[kSize] = 
	  {1, 2, 3, 4, 15, 6, 8, 10, 11 , 13};
	ASSERT_EQ(15, PeakFinder1DFast(array));
}

TEST(peak_finder, Test6){
	int array[kSize] = 
	  {11, 2, 3, 4, 5, 6, 8, 10, 11 , 13};
	EXPECT_TRUE(11 == PeakFinder1DFast(array) or  13 == PeakFinder1DFast(array) );
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}