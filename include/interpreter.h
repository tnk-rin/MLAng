#include <string>
#include <iostream>
#include "./nodes.h"
#include "./token.h"
#include "./types/integer.h"
class Interpreter {
	public:
		Interpreter() {};
		void visit(struct Nodes* node);
		Integer visitIntTree (struct Nodes* node);

	private:
		Integer visitNum (struct Nodes* node);
		Integer visitBinInt (struct Nodes* node);
};
	
