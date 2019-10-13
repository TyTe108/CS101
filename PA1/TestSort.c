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
 
  return(0);
}
