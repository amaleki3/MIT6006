#include "basic_algorithms/utils.h"

int main(){

  std::string doc_str1 = ReadFile("file1.tex");
  std::string doc_str2 = ReadFile("file2.tex");
  std::vector<std::string> words1 = BreakToWords(doc_str1);
  std::vector<std::string> words2 = BreakToWords(doc_str2);
  std::unordered_map<std::string, int> words_count1 = GetWordCounts(words1);
  std::unordered_map<std::string, int> words_count2 = GetWordCounts(words2);
  for (auto const& key : words_count1)
    std::cout << key.first << ": " << key.second << std::endl;
  for (auto const& key : words_count2)
    std::cout << key.first << ": " << key.second << std::endl;

  std::cout << "Similarity Angle is " 
            << ComputeSimilarityAngle(words_count1, words_count2)
            << " degrees" << std::endl;
  return 0;
}



// void passFunc(std::string tmp, int a[][10])
// {
//     for (int i=0; i< 5; i++){
// 			a[i][2] = 1.0;
//     	std::cout << a[i][2] << std::endl;
//     }
// }

// int main(){
// 	int arrayA[10][10];
// 	std::string tmp;
// 	passFunc(tmp, arrayA);
// }