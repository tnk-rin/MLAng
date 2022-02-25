#pragma once

#include <string>

const std::string TOKEN_INT = "INT";
const std::string TOKEN_PLUS = "PLUS";
const std::string TOKEN_MINUS = "MINUS";
const std::string TOKEN_MUL = "MUL";
const std::string TOKEN_DIV = "DIV";
const std::string TOKEN_LPAREN = "LPAREN";
const std::string TOKEN_RPAREN = "RPAREN";
const std::string TOKEN_EOF = "EOF";
const std::string TOKEN_NEGATE = "NEGATE";


class Token {
public:
	Token(std::string pType, std::string pValue) {
		type = pType;
		value = pValue;
	}

	Token(std::string pValue) {
		value = pValue;
		type = "OPERATOR";
	}

	Token() {}
	
	std::string str() {
		std::string to_return = "[ " + type + " : " + value + " ]";
		return to_return;
	}

	std::string type;
	std::string value;
};
