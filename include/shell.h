#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "./lexer.h"
#include "./parser.h"
#include "./token.h"

class Shell {
private:
	Parser parser;

public:
	Shell(Parser& _parser);
	void run();

};
