/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA3
 *========== */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BigInteger.h"

#define MAX_LEN 160

int main(int argc, char * argv[]){
  int n, count=0;
   FILE *in, *out;
   char line[MAX_LEN];
   char tokenList[4][MAX_LEN];
   char* token;

   // check command line for correct number of arguments
   if( argc != 3 ){
     printf("Usage: %s <input file> <output file>\n", argv[0]);
     exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
     printf("Unable to open file %s for reading\n", argv[1]);
     exit(1);
   }
   if( out==NULL ){
     printf("Unable to open file %s for writing\n", argv[2]);
     exit(1);
   }

   /* read each line of input file, then count and print tokens */
   while( fgets(line, MAX_LEN, in) != NULL)  {
      count++;
      // n = 0;
      token = strtok(line, " \n");
      //printf("Token is...: %s \n", token);
      if( token!=NULL ){
	strcpy(tokenList[n], token);
	//printf("TokenList: %s \n", tokenList[n]);
	n++;
      }
   }

      /* for(int i = 0; i < 4; i++){ */
      /* fprintf(out, "Output is %s\n", tokenList[i]); */
      /* } */




   //BigInteger Executions All Below

   //Output A
   BigInteger A = stringToBigInteger(tokenList[1]);
   printBigInteger(out, A);
   fprintf(out, "\n\n");

   //Output B
   BigInteger B = stringToBigInteger(tokenList[3]);
   printBigInteger(out, B);
   fprintf(out, "\n\n");

   //A+B
   BigInteger C = newBigInteger();
   add(C, A, B);
   printBigInteger(out, C);
   fprintf(out, "\n\n");
   freeBigInteger(&C);
   
   //A-B
   
   C = newBigInteger();
   subtract(C, A, B);
   printBigInteger(out, C);
   fprintf(out, "\n\n");
   freeBigInteger(&C);

   //A-A
   C  = newBigInteger();
   subtract(C,A,A);
   printBigInteger(out, C);
   fprintf(out, "\n\n");
   freeBigInteger(&C);

   //3A-2B
   BigInteger Three = stringToBigInteger("3");
   BigInteger Two = stringToBigInteger("2");
   


   C = prod(A, Three);
   BigInteger D = prod(B, Two);
   
   BigInteger E = diff(C, D);

   printBigInteger(out, E);
   fprintf(out, "\n\n");

   freeBigInteger(&C);
   freeBigInteger(&D);
   freeBigInteger(&E);

   //AB


   C = newBigInteger();
   multiply(C, A, B);
   printBigInteger(out, C);
   fprintf(out, "\n\n");

   /* printf("AB A:  \n"); */
   /* printBigInteger(stdout, A); */
   /* printf("\nAB B: \n"); */
   /* printBigInteger(stdout, B); */
   /* printf("\n"); */
   
   freeBigInteger(&C);
   
   //A^2
   D = newBigInteger();
   printf("\n");

   multiply(D, A, A);
   printBigInteger(out, D);
   fprintf(out, "\n\n");
   
   freeBigInteger(&D);

   //B^2
   D = newBigInteger();
   printf("\n");

   multiply(D, B, B);
   printBigInteger(out, D);
   fprintf(out, "\n\n");

   freeBigInteger(&D);

   //9A^4 + 16B^5
   D = newBigInteger();
   
   multiply(D, A, A);
   multiply(D, D, A);
   printf("Evolving D : ");
   printBigInteger(stdout, D);
   printf("\n");
   multiply(D, D, A);
   printf("Evolving D : ");
   printBigInteger(stdout, D);
   printf("\n");
   

   E = stringToBigInteger("9");
   BigInteger I = prod(D, E);

   printf("I: ");
   printBigInteger(stdout, I);
   printf("\n");

   BigInteger F = newBigInteger();

   multiply(F,B,B);
   multiply(F,F,B);
   multiply(F,F,B);
   multiply(F,F,B);

   BigInteger G = stringToBigInteger("16");
   BigInteger J = prod(F, G);

   printf("J: ");
   printBigInteger(stdout, J);
   printf("\n");

   BigInteger H = newBigInteger();
   add(H, I, J);

   printBigInteger(out, H);
   fprintf(out, "\n\n");

   freeBigInteger(&C);
   freeBigInteger(&D);
   freeBigInteger(&E);
   freeBigInteger(&F);
   freeBigInteger(&G);
   freeBigInteger(&H);
   freeBigInteger(&I);
   freeBigInteger(&J);
/* close file */
   fclose(in);
   fclose(out);
  return(0);
}

