#include "./shell.h"

/* -------------------------------------------------------------- *\
 * Shell class that takes in input and sends it to proper places, 
 * infinite loop for live interpreter when no file is specified.
\* -------------------------------------------------------------- */

void Shell::run() {
	printf("MLAng Interpreter (g++)\n\n");
	std::string prompt = ">> ",
		current_input;
	Lexer lexer = Lexer("");
	std::vector<Token> tokens;
	while(1) {
		std::cout << prompt;
		std::getline(std::cin, current_input);
		lexer = Lexer(current_input);
		tokens = lexer.make_token();

		Parser parser = Parser(tokens);
		struct Nodes* ast = parser.parse();

		std::cout << printTree(ast);
		//std::cout << "Syntax Tree: " << ast.str() << "\n\nLexer: ";

		//for(Token t : tokens)
		//	std::cout << t.str() << ", ";
		
		std::cout << "\n";
	}
}

std::string Shell::printTree(struct Nodes* tree) {

	std::string left, right, toReturn, node;

	switch(tree->mode) {
		case -1:
			return "empty tree";

		case -2:
			return tree->error->str();
		
		case 0:
			return tree->token.str();

		case 1:
			left = printTree(tree->left);
			right = printTree(tree->right);
			toReturn = "(" + left + tree->opToken.str() + right + ")";
			return toReturn;

		case 2:
			node = printTree(tree->node);
			toReturn = "(" + tree->opToken.str() + node + ")";
			return toReturn;

	}
	return "empty tree";
}

Shell::Shell() {
}
