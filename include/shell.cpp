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
		for(Token t : tokens) {
			std::cout << t.type << " : " << t.value << ", ";
		}
		std::cout << "\n";
	}
}

Shell::Shell(Parser& _parser) {
	parser = _parser;
}
