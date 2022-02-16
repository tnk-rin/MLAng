MAKEOPTIONS = -Wall

output: main.o lexer.o shell.o strsplit.o parser.o 
	clang++ $(MAKEOPTIONS) obj/main.o obj/lexer.o obj/shell.o obj/strsplit.o obj/parser.o -o mlang

main.o: src/main.cpp
	clang++ $(MAKEOPTIONS) -c src/main.cpp -o obj/main.o

lexer.o: include/lexer.cpp
	clang++ $(MAKEOPTIONS) -c include/lexer.cpp -o obj/lexer.o

parser.o: include/parser.cpp
	clang++ $(MAKEOPTIONS) -c include/parser.cpp -o obj/parser.o

shell.o: include/shell.cpp
	clang++ $(MAKEOPTIONS) -c include/shell.cpp -o obj/shell.o

strsplit.o: include/strsplit.cpp
	clang++ $(MAKEOPTIONS) -c include/strsplit.cpp -o obj/strsplit.o
