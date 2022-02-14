#pragma once

#include <string>

const std::string TOKEN_INT = "INT";
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

	Token(std::string _value) {
		value = _value;
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
