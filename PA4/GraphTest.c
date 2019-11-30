
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
 
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    
    BFS(A, 42);
    
    printf("Get Parent Test Print: \n");
    printGraph(stdout, A);
    
    int p = getParent(A,42);
    printf("Parent of 42 is %d \n", p);
    
    if (getParent(A, 42) != NIL){
        printf("getParent_Test #2 failed\n");
    }
    
    p = getParent(A,2);
    printf("Parent of 2 is %d \n", p);
    
    if (getParent(A, 2) != 42){
        printf("getParent_Test #3 failed\n");
    }
    if (getParent(A, 8) != NIL){
        printf("getParent_Test #4 failed\n");
    }
    printf("getParent_Test passed \n");
    freeGraph(&A);
 
    //----------DG_getDist_Test
    
    A = newGraph(100);
    for (int i = 1; i <= 100; i++){
        if (getDist(A, i) != INF){
            printf("DG_getDist_Test #1 failed\n");
        }
    }
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    BFS(A, 64);
    if (getDist(A, 64) != 0){
            printf("DG_getDist_Test #2 failed\n");    
    }
    if (getDist(A, 2) != 2){
            printf("DG_getDist_Test #3 failed\n");    
    }
    BFS(A, 4);
    if (getDist(A, 42) != 4){
        printf("DG_getDist_Test #4 failed\n");
    }
    if (getDist(A, 43) != INF){
        printf("DG_getDist_Test #5 failed\n");
    }
    BFS(A, 99);
    if (getDist(A, 64) != INF){
        printf("DG_getDist_Test #6 failed\n");
    }
    freeGraph(&A);
    printf("DG_getDist_Test passed \n");
    //----------DG_getPath:
    A = newGraph(100);
    List L = newList();
    List C = newList();
    
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    BFS(A, 3);
    
    getPath(L, A, 64);
    append(C, 3);
    append(C, 42);
    append(C, 2);
    append(C, 64);
    if (!equals(L, C)){
        printf("DG_getPath_Test #1 failed\n");
    }
    
    moveFront(L);
    BFS(A, 2);
    getPath(L, A, 2);
    append(C, 2);
    if (!equals(L, C)){
        printf("DG_getPath_Test #2 failed\n");
    }
    getPath(L, A, 99);
    if (equals(L, C)){
        printf("DG_getPath_Test #3 failed\n");
    }
    clear(L);
    clear(C);
    append(C, NIL);
    BFS(A, 99);
    getPath(L, A, 2);
    if (!equals(C, L)){
        printf("DG_getPath_Test #4 failed\n");
    }
    
    printf("DG_getPath_Test passed \n");
    
    freeGraph(&A);
    freeList(&L);
    freeList(&C);
 
 //UG_getSize_Test-------------------
    A = newGraph(100);
    
    if (getSize(A) != 0){
        printf("UG_getSize_Test #1 failed\n");
    }
  
    addEdge(A, 54, 1);
    addEdge(A, 54, 2);
    addEdge(A, 54, 3);
    addEdge(A, 1, 55);
    if (getSize(A) != 4){
        printf("UG_getSize_Test #2 failed\n");
    }
    BFS(A, 67);
    if (getSize(A) != 4){
        printf("UG_getSize_Test #3 failed\n");
    }
    addEdge(A, 55, 2);
    if (getSize(A) != 5)
        printf("UG_getSize_Test #4 failed\n");
    }
    printf("UG_getSize_Test passed \n");
    
    freeGraph(&A);
    
//UG_getSource_Test-------------
A = newGraph(100);    
if (getSource(A) != NIL){
    printf("UG_getSource_Test #1 failed\n");
};        
BFS(A, 42);        
if (getSource(A) != 42){
    printf("UG_getSource_Test #2 failed\n");
};        
BFS(A, 88);
if (getSource(A) != 88){
    printf("UG_getSource_Test #3 failed\n");
};
printf("G_getSource_Test passed \n");
freeGraph(&A);
return(0);
}
