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
    
    printf("Sign_Test C:  \n");
    printBigInteger(stdout, C);
    printf("\nSign Test D: \n");
    printBigInteger(stdout, D);
    printf("\n");
    
    if(sign(C) != 1 || sign(D) != -1){
        printf("Sign Test Failed 2 \n");
    }
    freeBigInteger(&A);
    freeBigInteger(&C);
    freeBigInteger(&D);
    
    printf("Sign Tests Passed \n");
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
    
    printf("Negate_tests Passed \n");
    //-----------------------------------------
    
    A = stringToBigInteger("+13378008135");
    makeZero(A);
    if(sign(A) != 0){
        printf("Makezero_test Failed 1 \n");
    }
    freeBigInteger(&A);
    
    printf("Makezero_tests Passed \n");
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
   
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    
    printf("Copy_tests Passed \n");
    
    //-----------------------------------------
    
    A = stringToBigInteger("+13378008135");
    B = stringToBigInteger("+13378008135");
    C = stringToBigInteger("+14378008135");
    D = stringToBigInteger("-13378008135");

    if(compare(A,B) != 0){
        printf("compare_test Failed 1 \n");
    }
    if(compare(A,C) != -1){
        printf("compare_test Failed 2 \n");
    }
    if(equals(A,B) != 1){
        printf("equal_test Failed 1 \n");
    }
    
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    freeBigInteger(&D);
    
    printf("compare & equal_tests Passed \n");
    
    //------------------------------
    
    A = stringToBigInteger("+111122223333");
    B = stringToBigInteger("+222211110000");
    C = newBigInteger();

    //pos + pos = pos
            
    D = stringToBigInteger("+333333333333");
    add(C, A, B);
    
    if(!equals(C, D)){
        printf("add_test Failed 1 \n");
    }
    
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    freeBigInteger(&D);
    printf("add_tests Passed \n");
return(0);
}
