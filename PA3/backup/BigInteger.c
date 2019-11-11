#include <math.h>
#include "BigInteger.h"

#define POWER 9
#define BASE pow(10, POWER)

BigInteger newBigInteger(){
  BigInteger B = (struct BigIntegerObj *) malloc(sizeof(struct BigIntegerObj)); //Dynamic Memory #1
  B->_sign = 0;
  B->_digit = 0
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
  
  B->_sign = 0;
  B->_digit = 0;
  
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
