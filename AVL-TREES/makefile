tum: derleme bagla calistir


derleme:
	g++  -I ./include/ -o ./lib/main.o -c ./src/main.cpp 
	g++  -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp 
	g++  -I ./include/ -o ./lib/avl.o -c ./src/avl.cpp 
	g++  -I ./include/ -o ./lib/stacknode.o -c ./src/stacknode.cpp 
	g++  -I ./include/ -o ./lib/stack.o -c ./src/stack.cpp 
	g++  -I ./include/ -o ./lib/stackListeNode.o -c ./src/stackListeNode.cpp 
	g++  -I ./include/ -o ./lib/stackListe.o -c ./src/stackListe.cpp 

bagla:
	g++ -I ./include/ ./lib/main.o ./lib/dugum.o ./lib/avl.o ./lib/stacknode.o ./lib/stack.o ./lib/stackListeNode.o ./lib/stackListe.o -o ./bin/program
	
calistir:
	./bin/program