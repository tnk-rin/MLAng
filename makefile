output: main.o lexer.o parser.o shell.o strsplit.o
	g++ obj/main.o obj/lexer.o obj/parser.o obj/shell.o obj/strsplit.o -o mlang

main.o: src/main.cpp
	g++ -c src/main.cpp -o obj/main.o

lexer.o: include/lexer.cpp
	g++ -c include/lexer.cpp -o obj/lexer.o

parser.o: include/parser.cpp
	g++ -c include/parser.cpp -o obj/parser.o

shell.o: include/shell.cpp
	g++ -c include/shell.cpp -o obj/shell.o

strsplit.o: include/strsplit.cpp
	g++ -c include/strsplit.cpp -o obj/strsplit.o

