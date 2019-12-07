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
    List L = newList();
    
    //DG_getSize============================
    if (getSize(A) != 0){
        printf("getSize() #1 test failed. \n");
    }
    
    addArc(A, 54, 1);
    addArc(A, 54, 2);
    addArc(A, 54, 3);
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    if (getSize(A) != 5){
        printf("getSize() #2 test failed. \n");
    }
    for (int8_t i = 1; i <= 100; i++) {
        append(L, i);
    }
    DFS(A, L);
    if (getSize(A) != 5){
        printf("getSize() #3 test failed. \n");    
    }
    addArc(A, 55, 1);
    if (getSize(A) != 6){
        printf("getSize() #3 test failed. \n");    
    }
    printf("getSize() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
return(0);
}
