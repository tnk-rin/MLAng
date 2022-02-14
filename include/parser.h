#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include "./token.h"
#include "./nodes.h"

class Parser {
	public:
		Parser(std::vector<Token> pTokens);
		Token advance();
		Node factor();
		Node term();
		Node expression();
		Node binaryOp(uint8_t mode, std::vector<std::string> operators);
		Node parse();
	private:
		std::vector<Token> tokens;
		int64_t token_index;
		Token current_token;
};
