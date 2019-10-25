#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 2
#
#       make                   makes Lex
#       make ListClient        makes ListTest
#	make MatrixTest	       make Sparse
#------------------------------------------------------------------------------

Sparse : Sparse.o Matrix.o
	gcc -o Sparse Sparse.o Matrix.o

Sparse.o : Sparse.c Matrix.h
	gcc -c -std=c99 -Wall Sparse.c

MatrixTest : MatrixTest.o Matrix.o
	gcc -o MatrixTest MatrixTest.o Matrix.o

MatrixTest.o : MatrixTest.c Matrix.h
	gcc -c -std=c99 -Wall MatrixTest.c

ListTest: ListTest.o List.o
	gcc -o ListTest ListTest.o List.o

ListTest.o : ListTest.c List.h
	gcc -c -std=c99 -Wall ListTest.c
	
Matrix.o : Matrix.c Matrix.h List.h
	gcc -c -std=c99 -Wall Matrix.c	
	
List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c
	
clean :
	rm -f Sparse MatrixTest ListTest Sparse.o MatrixTest.o ListTest.o List.o
 
