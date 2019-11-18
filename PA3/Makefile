#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 3
#
# make                   
# makes ListTest
#	make BigIntegerTest
# make Arithmetic
#------------------------------------------------------------------------------

ListTest: ListTest.o List.o
	gcc -o ListTest ListTest.o List.o

ListTest.o : ListTest.c List.h
	gcc -c -std=c99 -Wall ListTest.c

BigIntegerTest: BigIntegerTest.o BigInteger.o List.o
	gcc -o BigIntegerTest BigIntegerTest.o  List.o BigInteger.o

BigIntegerTest.o : BigIntegerTest.c BigInteger.h
	gcc -c -std=c99 -Wall BigIntegerTest.c	


Arithmetic: Arithmetic.o BigInteger.o List.o
	gcc -o Arithmetic Arithmetic.o  List.o BigInteger.o

Arithmetic.o : Arithmetic.c BigInteger.h
	gcc -c -std=c99 -Wall Arithmetic.c	

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

BigInteger.o : BigInteger.c BigInteger.h
	gcc -c -std=c99 -Wall BigInteger.c

clean :
	rm -f  ListTest ListTest.o List.o BigIntegerTest BigIntegerTest.o Arithmetic Arithmetic.o
