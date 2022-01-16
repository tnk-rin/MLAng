#pragma once

#include <string>

const std::string TOKEN_INT = "INT";
const std::string TOKEN_FLOAT = "FLOAT";
const std::string TOKEN_PLUS = "PLUS";
const std::string TOKEN_MINUS = "MINUS";
const std::string TOKEN_MUL = "MUL";
const std::string TOKEN_DIV = "DIV";
const std::string TOKEN_LPAREN = "LPAREN";
const std::string TOKEN_RPAREN = "RPAREN";

class Token {
public:
	Token(std::string _type, std::string _value) {
		type = _type;
		value = _value;
	}

	Token(std::string _type) {
		type = _type;
		value = "OPERATOR";
	}

	std::string type;
	std::string value;

};
