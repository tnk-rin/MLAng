#include "./strsplit.h" 

std::vector<std::string> split(const std::string &s, char line_delim, char word_delim) {
	std::vector<std::string> words;
	std::vector<std::string> lines;
	std::stringstream ss(s);
	std::string line, word;

	while(getline(ss, line, line_delim))
		lines.push_back(line);
	for(std::string w : lines) {
		std::stringstream sw(w);
		while(getline(sw, word, word_delim)) {
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (word != "")
				words.push_back(word);
		}
		words.push_back("EOL");
	}
	return words;
}
