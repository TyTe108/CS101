#include <math.h>
#include "BigInteger.h"
#include<string.h>
#include <stdlib.h>
#include<stdio.h> 
#include "List.h"

#define POWER 9
#define BASE pow(10, POWER)

BigInteger newBigInteger(){
  BigInteger B = (struct BigIntegerObj *) malloc(sizeof(struct BigIntegerObj)); //Dynamic Memory #1
  B->_sign = 0;
  B->_digit = 0;
  B->_L = newList();  //Dynamic Memory #2
  return B;
}

void freeBigInteger(BigInteger* pN){
  BigInteger N = *pN;
  if (N == NULL){
    return; 
  }
  
  List L = N->_L;
  freeList(&L); //Dynamic Memory #2
  
  N->_sign = 0;
  N->_digit = 0;
  
  free(*pN); //Dynamic Memory #1
  *pN = NULL;
}

// Access functions -----------------------------------------------------------

// sign()
// Returns -1 if N is negative, 1 if N is positive, and 0 if N is in the zero
// state.
int sign(BigInteger N){
  return (N->_sign);
}

// compare()
// Returns -1 if A<B, 1 if A>B, and 0 if A=B.
int compare(BigInteger A, BigInteger B){
  int res;
  
  //.......
  
  return res;
}

// stringToBigInteger()
// Returns a reference to a new BigInteger object representing the decimal integer
// represented in base 10 by the string s.
// Pre: s is a non-empty string containing only base ten digits {0,1,2,3,4,5,6,7,8,9}
// and an optional sign {+, -} prefix.
BigInteger stringToBigInteger(char* s){
    //precondition
    //find how many digits in the BigInt
    int digitLen = strlen(s);
    
    if (digitLen <= 0){
        printf("Calling stringToBigInteger() on an empty string \n");
        return NULL;
    }
    BigInteger B = newBigInteger();
    B->_digit = ceil(digitLen/POWER);
  
  
    //Taking Care of the sign
    if(((s[0]) == '+') | ((s[0]) == '-')){
        if(s[0] == '+'){
            B->_sign = 1;
        }else if (s[0] == '-'){
            B->_sign = -1;
        }
        s++;  
    }
    
    printf(" Works 1: Printing S: \n");
    printf(s);
    printf("\n");
  
    char sC[strlen(s) + 1];
    strcpy(sC, s);
  
    printf(" Works 2 \n"); 
    strrev(sC);
    printf(" Works 3.1: Printing reversed sC: \n");
    printf(sC);
    printf("\nWorks 3.2\n");
    int stop = 0;
  
  
    //There's a reverse issue that's needs to be fixed
    while (stop == 0){
        char toFloat[POWER+1];
        printf(" Works 4.1 \n"); 
        strncpy(toFloat, sC, POWER);
        printf(" Works 4.2: Printing reversed toFloat: %s\n", toFloat); 
      
        //Convert toFloat string to Float...
        strrev(toFloat); //this fixes the reverse issue
        printf(" Works 5: printing toFloat: %s \n", toFloat); 
            
        float converted = strtof(toFloat, NULL);
        printf(" Works 6 \n"); 
        append(B->_L, converted);
        
        if(strlen(toFloat) < POWER){
            stop = 1;
        }else{
            strrev(sC);
            printf(" Works 7 \n"); 
            char sC2[(strlen(sC) - POWER) + 1];
            strncpy(sC2, sC, (strlen(sC) - POWER));
            strcpy(sC, sC2);
            printf(" Works 8 \n"); 
            strrev(sC);
            printf(" Works 9 \n"); 
        }
    }

    return B;
}

void strrev(char* s){
        char *p1, *p2;

      if (! s || ! *s)
            return;
      for (p1 = s, p2 = s + strlen(s) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
}
