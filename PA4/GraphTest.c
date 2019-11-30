
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
    printGraph(stdout, A);
    
    BFS(A, 67);
    if (getSize(A) != 5){
        printf("getSize() #3 test failed because of faulty addArc \n");
    }
    
    addArc(A, 55, 1);
    
    if (getSize(A) != 6){
        printf("getSize() #4 test failed because of faulty addArc \n");

    } 
    printGraph(stdout, A);
    
    printf("getSize() test passed \n");
    
    freeGraph(&A);
    //----------GetSource_Test
    
    A = newGraph(100);
    if (getSource(A) != NIL){
        printf("GetSource_Test test #1 failed\n");
    }
    
    BFS(A, 42);
    
    if (getSource(A) != 42){
        printf("GetSource_Test test #2 failed\n");
    }
        
    BFS(A, 88);
    if (getSource(A) != 88){
        printf("GetSource_Test test #2 failed\n");
    }
    printf("GetSource_Test tests passed \n");
    freeGraph(&A);
 
 //----------DG_getParent_Test
 
 A = newGraph(100);
 
 for (int i = 1; i <= 100; i++){
     if (getParent(A, i) != NIL){
         printf("getParent_Test #1 failed\n");
     }
 }
    printf("getParent_Test passed \n");
    freeGraph(&A);
 return(0);
}
