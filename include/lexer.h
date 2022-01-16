#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "./strsplit.h"
#include "./error.h"
#include "./token.h"

class Lexer {
public:
	Lexer(const std::string& _text);
	void advance();
	std::vector<Token> make_token();

private:
	std::vector<std::string> text;
	int position;
	std::string curr_word;
	bool is_number(const std::string& s);
};
