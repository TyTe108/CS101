/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA1
 *========== */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 160






int main(int argc, char * argv[]){
   int n, count=0;
   FILE *in, *out;
   char line[MAX_LEN];
   char tokenlist[MAX_LEN];
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

   //Get number of lines first
   char ch;
   for (ch = getc(in); ch != EOF; ch = getc(in)) 
     if (ch  == '\n'){
       count++;
     }
   printf("count is %d\n", count);

   //Create an array of strings  size count 
   char arrayOfString[count][MAX_LEN];
   int i = 0; //iterator for array of strings

   //Open again because finding the size wiped everything
   in = fopen(argv[1], "r");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   /* read each line of input file, then count and print tokens */
   while( fgets(line, MAX_LEN, in) != NULL)  {
     // count++;
      n = 0;
      token = strtok(line, " \n");
      tokenlist[0] = '\0';
      while( token!=NULL ){
         strcat(tokenlist, "   ");
         strcat(tokenlist, token);
         //strcat(tokenlist, "\n");
         n++;
         token = strtok(NULL, " \n");
      }
      	
	strcpy(arrayOfString[i],tokenlist);
	printf("The arrayOfString are: \n");
	printf(arrayOfString[i]);
	//printf("\n");
	i++;
	
      fprintf(out, "line %d contains %d token%s: \n", count, n, n==1?"":"s");
      fprintf(out, "%s\n", tokenlist);
      fprintf(out, "count: %d \n", count);

   }


   //Create a List whose elements are the indices of the above string array. 
   //These indices should be arranged in an order that indirectlysorts 
   //the array.  Using the above input file as an example we would have.

   List indicesList = newList(); //indices list constructed
   for (int i = 0; i < count; i++){ //make i 0 again to reuse, now iterate through
	   if (length(indicesList) == 0){
		//if indicesList is an empty list, just append the first index into it, no need to compare
		   append(indicesList,i);
	   }else{
		   moveFront(indicesList); //move to head to start comparint each one
		   while(index(indicesList)<length(indicesList)){
			   int result = strcmp(arrayOfString[get(indicesList)], arrayOfString[i]);
			   if (result >= 0){
				   insertBefore(indicesList,i);
				   moveBack(indicesList);
			   }
			   else{
				   int ind = index(indicesList);
				   if (ind == length(indicesList)-1){ //if tail, just insertAfter the tail
					   append(indicesList,i);
					   moveBack(indicesList);	   
				   }
				   else{
					   moveNext(indicesList); //go to the next one
				   }
			   }
		   }
	   }
   }
		 
   printList(stdout, indicesList);
   freeList(&indicesList);

   
   /* close files */

   fclose(in);
   fclose(out);

   return(0);
}
  
