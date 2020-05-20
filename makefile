all: piece.o partie.o main.o 
	gcc -g piece.o partie.o main.o -o main.exe
main.o : main.c partie.h
	gcc -c main.c -o main.o
piece.o :piece.c piece.h
	gcc -c piece.c -o piece.o
partie.o :partie.c partie.h
	gcc -c partie.c -o partie.o


