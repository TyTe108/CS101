
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
     printf("getSize() #1 test failed. \n"); 
 }
    addArc(A, 54, 1);    
    addArc(A, 54, 2);  
    addArc(A, 54, 3);      
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    if (getSize(A) != 5){
        printf("getSize() #2 test failed because of faulty addArc \n");
    }
    
    printf("getSize() test passed \n");
 return(0);
}
