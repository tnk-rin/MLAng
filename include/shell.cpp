#include "./shell.h"

/* -------------------------------------------------------------- *\
 * Shell class that takes in input and sends it to proper places, 
 * infinite loop for live interpreter when no file is specified.
\* -------------------------------------------------------------- */

void Shell::run() {
	std::string message = "MLAng Interpreter (";
	message += cxx + " " + cxx_ver + ")\n\n";
	std::cout << message;
	std::string prompt = ">> ",
		current_input;
	Lexer lexer = Lexer("");
	std::vector<Token> tokens;
	while(1) {
		std::cout << prompt;
		std::getline(std::cin, current_input);
		lexer = Lexer(current_input);
		tokens = lexer.make_token();
		if (tokens.size() == 0)
			continue;
		if(tokens.at(0).type == "INTERNAL" && tokens.at(0).value == "__abort_interpreter")
			return;
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
	if (tree == NULL)
		return "empty tree";

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
