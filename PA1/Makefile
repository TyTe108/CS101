#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 1
#
#       make                   makes Lex
#       make ListClient        makes ListClient
#------------------------------------------------------------------------------

Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c
	
TestSort : TestSort.o List.o
	gcc -o TestSort TestSort.o List.o

TestSort.o : TestSort.c List.h
	gcc -c -std=c99 -Wall TestSort.c	

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o
 
