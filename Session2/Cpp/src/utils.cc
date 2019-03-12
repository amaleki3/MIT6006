#include "basic_algorithms/utils.h"

std::string ReadFile(std::string file_name){

	std::ifstream fid;
	fid.open(file_name);
	if (!fid){
		std::cerr << "Unable to open file " << file_name << std::endl;
    	exit(1);   // call system to stop
	}

	std::string content = "", x;
	while (fid >> x){
  		boost::algorithm::to_lower(x);
  		content = content + x + " ";
  	}
  	fid.close();

	return content;
}

std::vector<std::string> BreakToWords(std::string doc_str){
	std::string this_word = "";
	std::vector<std::string> words;
	for (int i = 0; i < doc_str.length(); i++)
		if (isalpha(doc_str[i]))
			this_word = this_word + doc_str[i];
		else {
			if (this_word.length() > 0)
				words.push_back(this_word);
			this_word = "";
		}
	return words;
}

std::unordered_map<std::string, int> GetWordCounts(std::vector<std::string> words){
	std::unordered_map<std::string, int> words_count = {};
	for(int i = 0; i < words.size(); i++)
		words_count[words[i]] ++;
	return words_count;
}

float ComputeSimilarityAngle (std::unordered_map<std::string, int> words_count1,
 std::unordered_map<std::string, int> words_count2){
	int dot_product = 0, abs_words_count1 = 0, abs_words_count2 = 0;
	for (auto const& key : words_count1)
  	abs_words_count1 += key.second*key.second;
  for (auto const& key : words_count2)
  	abs_words_count2 += key.second*key.second;
  for (auto const& key : words_count1)
  	dot_product += key.second*words_count2[key.first];
	
  return acos(dot_product/pow(abs_words_count1*abs_words_count2,0.5))*180./M_PI;
}
