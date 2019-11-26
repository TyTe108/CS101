#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 4
#
#------------------------------------------------------------------------------

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c
  
GraphTest: GraphTest.o Graph.o List.o
	gcc -o GraphTest GraphTest.o  List.o Graph.o

GraphTest.o : GraphTest.c Graph.h
	gcc -c -std=c99 -Wall GraphTest.c
  
Graph.o : Graph.c Graph.h
	gcc -c -std=c99 -Wall Graph.c

clean :
	rm -f List.o GraphTest.o Graph.o GraphTest
