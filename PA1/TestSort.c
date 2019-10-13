#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 160
int main(){  
  int count = 5;
  char arrayOfString[count][MAX_LEN];

  strcpy(arrayOfString [1], "one");

  strcpy(arrayOfString [2], "two");

  strcpy(arrayOfString [3], "three");

  strcpy(arrayOfString [4], "four");

  strcpy(arrayOfString [5], "five");

  printf(arrayOfString[1]);
  printf("\n");
  
  
  List indicesList = newList(); //indices list constructed
   for (int i = 0; i < count; i++){ //make i 0 again to reuse, now iterate through
	   if (length(indicesList) == 0){
		//if indicesList is an empty list, just append the first index into it, no need to compare
		   append(indicesList,i);
		   printf("#1\n");
	   }else{
		   moveFront(indicesList); //move to head to start comparint each one
		   printf("#2\n");
		   while(index(indicesList)<length(indicesList)){
			   int result = strcmp(arrayOfString[get(indicesList)], arrayOfString[i]);
			   printf("#3\n");
			   if (result >= 0){
				   printf("#4\n");
				   insertBefore(indicesList,i);
				   printf("#5\n");
				   moveBack(indicesList);
				   printf("#6\n");
				   printf("STUCK AT: ");
				   printf(arrayOfString[i]);
				   printf("\n");
			   }
			   else{
				   int ind = index(indicesList);
				   printf("#7\n");
				   if (ind == length(indicesList)-1){ //if tail, just insertAfter the tail
					   printf("#8\n");
					   append(indicesList,i);
					   printf("#9\n");
					   moveBack(indicesList);
					   printf("#10\n");
				   }
				   else{
					   printf("#11\n");
					   moveNext(indicesList); //go to the next one
					   printf("#12\n");
				   }
			   }
		   }
	   }
   }
		 
   printList(stdout, indicesList);
   freeList(&indicesList);
 
  return(0);
}
