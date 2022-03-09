MAKEOPTIONS = -Wall -std=c++11
CC = clang++

output: main.o lexer.o shell.o strsplit.o parser.o interpreter.o 
	$(CC) $(MAKEOPTIONS) obj/main.o obj/lexer.o obj/shell.o obj/strsplit.o obj/parser.o obj/interpreter.o -o mlang

main.o: src/main.cpp
	$(CC) $(MAKEOPTIONS) -c src/main.cpp -o obj/main.o

lexer.o: include/lexer.cpp
	$(CC) $(MAKEOPTIONS) -c include/lexer.cpp -o obj/lexer.o

parser.o: include/parser.cpp
	$(CC) $(MAKEOPTIONS) -c include/parser.cpp -o obj/parser.o

shell.o: include/shell.cpp
	$(CC) $(MAKEOPTIONS) -c include/shell.cpp -o obj/shell.o

strsplit.o: include/strsplit.cpp
	$(CC) $(MAKEOPTIONS) -c include/strsplit.cpp -o obj/strsplit.o

interpreter.o: include/interpreter.cpp
	$(CC) $(MAKEOPTIONS) -c include/interpreter.cpp -o obj/interpreter.o
