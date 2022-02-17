#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdint.h>
#include "./token.h"
#include "./nodes.h"
#include "./error.h"

class Parser {
	public:
		Parser(std::vector<Token> pTokens);
		Token advance();

		struct Nodes* factor();
		struct Nodes* term();
		struct Nodes* expression();
		struct Nodes* binaryOp(uint8_t mode, std::vector<std::string> operators);
		struct Nodes* parse();

		/*
		Node factor();
		Node term();
		Node expression();
		Node binaryOp(uint8_t mode, std::vector<std::string> operators);
		Node parse();
		*/
	private:
		std::vector<Token> tokens;
		int64_t token_index;
		Token current_token;
};
