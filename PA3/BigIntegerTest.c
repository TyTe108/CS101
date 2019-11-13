/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA2
 *========== */

#include "BigInteger.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    BigInteger A = newBigInteger();
    if (sign(A) != 0){
        printf("Sign Test Failed \n");
    }

            BigInteger C = stringToBigInteger("+13378008135");
            BigInteger D = stringToBigInteger("-13378008135");
            if(sign(C) != 1 || sign(D) != -1) return 1;

            freeBigInteger(&C);
            freeBigInteger(&D);

return(0);
}
