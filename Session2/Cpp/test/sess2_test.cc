#include <gtest/gtest.h>

#include "basic_algorithms/utils.h"

TEST(distance, Test1){
	std::string doc_str1 = ReadFile("file1.tex");
  std::vector<std::string> words1 = BreakToWords(doc_str1);
  std::unordered_map<std::string, int> words_count1 = GetWordCounts(words1);
	ASSERT_EQ(0, ComputeSimilarityAngle(words_count1, words_count1));
}

TEST(distance, Test2){
	std::string doc_str1 = ReadFile("file1.tex");
  std::string doc_str2 = ReadFile("file2.tex");
  std::vector<std::string> words1 = BreakToWords(doc_str1);
  std::vector<std::string> words2 = BreakToWords(doc_str2);
  std::unordered_map<std::string, int> words_count1 = GetWordCounts(words1);
  std::unordered_map<std::string, int> words_count2 = GetWordCounts(words2);
  ASSERT_EQ(acos(6./7.)*180./M_PI, ComputeSimilarityAngle(words_count1, words_count2));
}

TEST(distance, Test3){
	std::string doc_str1 = ReadFile("file1.tex");
  std::string doc_str3 = ReadFile("file3.tex");
  std::vector<std::string> words1 = BreakToWords(doc_str1);
  std::vector<std::string> words3 = BreakToWords(doc_str3);
  std::unordered_map<std::string, int> words_count1 = GetWordCounts(words1);
  std::unordered_map<std::string, int> words_count3 = GetWordCounts(words3);
  ASSERT_EQ(90, ComputeSimilarityAngle(words_count1, words_count3));
}


int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}