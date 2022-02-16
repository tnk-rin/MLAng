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

		//std::cout << "Syntax Tree: " << ast.str() << "\n\nLexer: ";

		//for(Token t : tokens)
		//	std::cout << t.str() << ", ";
		
		std::cout << "\n[ " << ast->left->token.str() << " " << ast->opToken.str() << " " << ast->right->opToken.str() << " " << ast->right->left->token.str() << " : " << ast->right->right->token.str() << " ] \n";

		std::cout << "\n";
	}
}

Shell::Shell() {
}
