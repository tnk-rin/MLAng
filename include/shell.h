#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "./lexer.h"
#include "./token.h"
#include "./parser.h"
#include "./nodes.h"

class Shell {
private:

public:
	Shell();
	std::string printTree(struct Nodes* tree);
	void run();

};
