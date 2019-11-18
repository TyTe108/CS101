/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA3
 *========== */

#include "BigInteger.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
    long test = 10;
    printf("Printing long: %li \n",test);

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
    
    
     printf("Add_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nAdd_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");

    //pos + pos = pos
            
    D = stringToBigInteger("+333333333333");
    add(C, A, B);
    
    printf("Add_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    
    if(!equals(C, D)){
        printf("add_test Failed 1 \n");
    }
    freeBigInteger(&B);
    freeBigInteger(&D);
    
    B = stringToBigInteger("-111122223333");
    add(C, A, B);
    if(sign(C) != 0) {
        printf("add_test Failed 2 \n");
    }
    
    printf("Add_Test #2: \n");
    printf("Add_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nAdd_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Add_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    freeBigInteger(&B);

    B = stringToBigInteger("-110122223333");
    add(C, A, B);
    if(sign(C) != 1){
        printf("add_test Failed 3 \n");
    }
    
    printf("Add_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nAdd_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Add_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");
    
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    
    printf("add_tests Passed \n");


    //---------------------------
    A = stringToBigInteger("+111122223333");
    B = stringToBigInteger("+222211110000");

    //pos + pos = pos
    D = stringToBigInteger("+333333333333");
    C = sum(A, B);

    if(!equals(C, D)){
      printf("sum_test Failed 1 \n");
    }

    printf("Sum_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nSum_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Sum_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");
    
    freeBigInteger(&B);
    freeBigInteger(&C);
    freeBigInteger(&D);

    negate(A); //A-> -111122223333
    B = stringToBigInteger("+111122223333");
    C = sum(A, B);
    if(sign(C) != 0){
      printf("sum_test Failed 2 \n");
    }

    printf("Sum_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nSum_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Sum_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    freeBigInteger(&B);
    freeBigInteger(&C);


    B = stringToBigInteger("+112122223333");
    C = sum(A, B);
    if(sign(C) != 1){
      printf("sum_test Failed 3 \n");
    }


    printf("Sum_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nSum_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Sum_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    freeBigInteger(&B);
    freeBigInteger(&C);
    

    B = stringToBigInteger("+110122223333");
    C = sum(A, B);
    if(sign(C) != -1){
      printf("sum_test Failed 4 \n");
    }

    printf("Sum_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nSum_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Sum_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    freeBigInteger(&B);
    freeBigInteger(&C);

    B = stringToBigInteger("-222211110000");
    D = stringToBigInteger("-333333333333");
    C = sum(A, B);
    if(!equals(C, D)){
      printf("sum_test Failed 5 \n");
    } 

    printf("Sum_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nSum_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("Sum_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");
    
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    freeBigInteger(&D);
    
    printf("sum_tests Passed \n");

    //Subtract Test-------------------------
    A = stringToBigInteger("+111122223333");
    B = stringToBigInteger("+111122223333");
    C = newBigInteger();
    
    subtract(C, A, B);
    if(sign(C) != 0){
      printf("subtract_test Failed 1\n");
    }

    printf("subtract_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nsubtract_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("subtract_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    freeBigInteger(&B);


    B = stringToBigInteger("121122223333");
    subtract(C, A, B);
    if(sign(C) != -1){
      printf("subtract_test Failed 2\n");
    }

    printf("subtract_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nsubtract_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("subtract_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    // pos - pos > 0
    freeBigInteger(&B);

    B = stringToBigInteger("101122223333");
    subtract(C, A, B);
    if(sign(C) != 1){
      printf("subtract_test Failed 3\n");
    }

    printf("subtract_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nsubtract_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("subtract_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    negate(B);
    subtract(C, A, B);
    if(sign(C) != 1){
      printf("subtract_test Failed 4\n");
    }
    printf("subtract_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nsubtract_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("subtract_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    subtract(C, B, A);
    if(sign(C) != -1){
      printf("subtract_test Failed 5\n");
    }


    printf("subtract_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nsubtract_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("subtract_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);

    printf("subtract_tests Passed \n");


    //Diff------------------------------
    A = stringToBigInteger("-111122223333");
    B = stringToBigInteger("-111122223333");

    //neg - neg = 0
    C = diff(A, B);
    if(sign(C) != 0){
      printf("diff__test Failed 1\n");
    }

    printf("diff_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\ndiff_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("diff_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    freeBigInteger(&B);
    freeBigInteger(&C);



    B = stringToBigInteger("-112122223333");
    C = diff(A, B);
    if(sign(C) != 1){
      printf("diff__test Failed 2\n");
    }

    printf("diff_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\ndiff_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("diff_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");



    freeBigInteger(&B);
    freeBigInteger(&C);

    B = stringToBigInteger("-110122223333");
    C = diff(A, B);
    if(sign(C) != -1){
      printf("diff__test Failed 3\n");
    }
    

    printf("diff_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\ndiff_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("diff_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");


    negate(B);
    freeBigInteger(&C);
    C = diff(A, B);
    if(sign(C) != -1){
      printf("diff__test Failed 4\n");
    }

    printf("diff_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\ndiff_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");
    printf("diff_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");

    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);

    printf("subtract_tests Passed \n");


    /* A = stringToBigInteger("111122223333"); */
    /* B = stringToBigInteger("111122223333"); */
    A = stringToBigInteger("-41085449");
    B = stringToBigInteger("7402779357");
    C = newBigInteger();


    printf("mult_Test A:  \n");
    printBigInteger(stdout, A);
    printf("\nmult_Test B: \n");
    printBigInteger(stdout, B);
    printf("\n");

    // pos * pos = pos
    multiply(C, A, B);
    if(sign(C) != 1){
      printf("mult__test Failed 1\n");
    }

    printf("mult_Test Sum C: \n");
    printBigInteger(stdout, C);
    printf("\n");
    printf("mult_tests Passed \n");
return(0);
}
