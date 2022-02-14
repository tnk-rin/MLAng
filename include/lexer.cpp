#include "./lexer.h"

Lexer::Lexer(const std::string& _text) {
	char line_delim = '.',
	     word_delim = ' ';
	text = split(_text, line_delim, word_delim);
	int EOL_count = 0;
	for(char c : _text) {
		if (c == line_delim)
			++EOL_count;
	}

	if(EOL_count == 0 && _text != "") {
		IllegalLineEnding warning = IllegalLineEnding(_text);
		std::cout << warning.str() << "\n";
	}
	position = -1;
	curr_word = "";
	advance();

}

void Lexer::advance() {
	++position;
	curr_word = (position < text.size()) ? text[position] : "EOL";
}

std::vector<Token> Lexer::make_token() {
	std::vector<Token> tokens;

	while (curr_word != "EOL") {
		if(curr_word == "plus")
			tokens.push_back(Token(TOKEN_PLUS));	
		else if(curr_word == "minus")
			tokens.push_back(Token(TOKEN_MINUS));	
		else if(curr_word == "times")
			tokens.push_back(Token(TOKEN_MUL));
		else if(curr_word == "divide")
			tokens.push_back(Token(TOKEN_DIV));
		else if(curr_word == "(")
			tokens.push_back(Token(TOKEN_LPAREN));
		else if(curr_word == ")")
			tokens.push_back(Token(TOKEN_RPAREN));
		else if(is_number(curr_word))
			tokens.push_back(Token(TOKEN_INT, curr_word));
		else {
			IllegalWordError error = IllegalWordError(curr_word);
			std::cout << error.str() << "\n";
			return error_lst; 
		}

		advance();
	}
	return tokens;
}

bool Lexer::is_number(const std::string& s) {
	for(char c : s) 
		if(std::isdigit(c) == 0) return false;
	return true;
}
