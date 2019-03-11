import math
import sys

def read_file(filename):
    """
    Read the text file with the given filename;
    return a list of the lines of text in the file.
    """
    try:
        f = open(filename, 'r')
        return f.read()
    except IOError:
        print('Error opening or reading input file: ', filename)
        sys.exit()

def break_to_words(doc):
    """
    breaks down a big string (from a file) into its words.
    non-alphabetic characters are used to seperate the words.
    the return is a list of words in lower case.
    """
    words = []
    this_word = ''
    for char in doc:
        if char.isalpha():
            this_word = this_word + char
        else:
            if len(this_word) > 0:
                words.append(this_word.lower())
            this_word = ''
    return words

def get_word_counts(word_list):
	"""
	compute frequency of each word in a list of words.
	"""
	word_counts = {}
	for word in word_list:
		if word in word_counts:
			word_counts[word] = word_counts[word] + 1
		else:
			word_counts[word] = 1
	return word_counts

def get_word_vectors_dot_product(word_dict1, word_dict2):
	"""
	compute dot product the frequency vector associated to the two given word dict.
	"""
	dot_product = 0
	abs_count1 = 0
	abs_count2 = 0
	for word in word_dict1.keys():
		if word in word_dict2.keys():
			dot_product = dot_product + word_dict1[word]*word_dict2[word]
	for word1, count1 in word_dict1.items():
		abs_count1 = abs_count1 + count1*count1
	for word2, count2 in word_dict2.items():
		abs_count2 = abs_count2 + count2*count2
	return math.acos(dot_product/(abs_count1*abs_count2)**(1/2))*180/math.pi

def main():
    if len(sys.argv) < 3:
        print('test mod is activated')
        doc1 = 'Amir Maleki is going to school and he is going to learn how to make \n capochino? Readlly, No way.'
        doc2 = 'Amir has already learnt how to make latte and flat white.'
    else:
        doc1 = read_file(sys.argv[1])
        doc2 = read_file(sys.argv[2])

    words1 = break_to_words(doc1)
    words2 = break_to_words(doc2)
    word_counts1 = get_word_counts(words1)
    word_counts2 = get_word_counts(words2)

    distance = get_word_vectors_dot_product(word_counts1, word_counts2)
    print('The distance between the documents is: %0.6f (radians)' % distance)


if __name__ == "__main__":
    main()
    # import profile
    # profile.run("main()")

