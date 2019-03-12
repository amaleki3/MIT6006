#ifndef INCLUDE_BASIC_ALGORITHM_UTILS_H
#define INCLUDE_BASIC_ALGORITHM_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <boost/algorithm/string.hpp>


std::string ReadFile(std::string file_name);
std::vector<std::string> BreakToWords(std::string doc_str);
std::unordered_map<std::string, int> GetWordCounts(std::vector<std::string> words);
float ComputeSimilarityAngle (std::unordered_map<std::string, int> words_count1,
 std::unordered_map<std::string, int> words_count2);
#endif // INCLUDE_BASIC_ALGORITHM_UTILS_H