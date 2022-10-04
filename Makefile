preprocess: Preprocess.o SymbolTable.o
	gcc -o preprocess Preprocess.o SymbolTable.o

Preprocess.o: Preprocess.c SymbolTable.h
	gcc -c Preprocess.c

SymbolTable.o: SymbolTable.c SymbolTable.h
	gcc -c SymbolTable.c