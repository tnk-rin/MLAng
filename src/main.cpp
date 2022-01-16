#include "../include/shell.h"

int main(int argc, char *argv[]) {
	//load file specified in command
	Parser parser;
	Shell shell = Shell(parser);
	shell.run();

}
