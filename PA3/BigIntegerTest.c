/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA3
 *========== */

#include "BigInteger.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){

    BigInteger A = newBigInteger();
    if (sign(A) != 0){
        printf("Sign Test Failed 1 \n");
    }
    BigInteger C = stringToBigInteger("+13378008135");
    BigInteger D = stringToBigInteger("-13378008135");
    if(sign(C) != 1 || sign(D) != -1){
        printf("Sign Test Failed 2 \n");
    }
    freeBigInteger(&A);
    freeBigInteger(&C);
    freeBigInteger(&D);
    //-----------------------------------------
    
    A = stringToBigInteger("+13378008135");
    negate(A);
    if(sign(A) != -1){
        printf("Negate_test Failed 1 \n");
    };
    negate(A);
    if(sign(A) != 1){
        printf("Negate_test Failed 2 \n");
    };
    freeBigInteger(&A);
    //-----------------------------------------
    
    A = stringToBigInteger("+13378008135");
    makeZero(A);
    if(sign(A) != 0){
        printf("Makezero_test Failed 1 \n");
    }
    freeBigInteger(&A);
    //-----------------------------------------
    A = stringToBigInteger("+13378008135");
    BigInteger B = copy(A);
    if(sign(B) != 1){
        printf("Copy_test Failed 1 \n");
    }
    negate(A);
    if(sign(B) != 1){
        printf("Copy_test Failed 2\n");
    }
    C = copy(A);
    if(sign(C) != -1){
        printf("Copy_test Failed 3 \n");
    }


return(0);
}
