
 /*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA4
 *========== */

#include<string.h>
#include <stdlib.h>
#include<stdio.h> 
#include "List.h"
#include "Graph.h"


int main(int argc, char* argv[]){
 Graph A = newGraph(100);
 
 if (getSize(A) != 0){
     printf("getSize() test failed. \n"); 
 }
 
 return(0);
}
