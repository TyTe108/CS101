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
 
  return(0);
}
