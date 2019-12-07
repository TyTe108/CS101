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
    for (int i = 1; i <= 100; i++) {
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
    
    //DG_getParent============================
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getParent(A, i) != NIL){
            printf("getParent() test #1 failed. \n");   
        }
    }
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        append(L, i);
    }
    
    printf("Print the Graph: \n");
    printGraph(stdout, A);
    
    DFS(A, L);
    if (getParent(A, 100) != NIL){
        printf("getParent() test #2 failed. \n");   
    }
    if (getParent(A, 2) != NIL){
        printf("getParent() test #3 failed. \n");   
    }
    if (getParent(A, 42) != 3){
        printf("getParent() test #4 failed. \n");   
    }
    if (getParent(A, 3) != 64){
        printf("getParent() test #5 failed. \n");   
    }
    if (getParent(A, 4) != 64){
        printf("getParent() test #6 failed. \n");   
    }
    printf("getParent() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //DG_getDiscover============================

    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
          if (getDiscover(A, i) != UNDEF){
             printf("getDiscover() test #1 failed. \n");   
          }
    }
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        prepend(L, i);
    }
    DFS(A, L);
    if (getDiscover(A, 100) != 1){
        printf("getDiscover() test #2 failed. \n");
    }
    
    printf("Print the Graph: \n");
    printGraph(stdout, A);
    
    printf("getDiscover() of v 64 is %d\n", getDiscover(A, 64));
    if (getDiscover(A, 64) != 73){
        printf("getDiscover() test #3 failed. \n");
    }
    if (getDiscover(A, 4) != 80){
        printf("getDiscover() test #4 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 4) != 126){
        printf("getDiscover() test #5 failed. \n");
    }
    if (getDiscover(A, 63) != 117){
        printf("getDiscover() test #6 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 65) != 71){
        printf("getDiscover() test #7 failed. \n");
    }
    if (getDiscover(A, 1) != 199){
        printf("getDiscover() test #8 failed. \n");
    }
    printf("getDiscover() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //DG_getFinish============================
    
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getFinish(A, i) != UNDEF){
            printf("getFinish() test #1 failed. \n");   
        }
    }
    
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        prepend(L, i);
    }
    DFS(A, L);
    if (getFinish(A, 100) != 2){
        printf("getFinish() test #2 failed. \n");
    }
    if (getFinish(A, 64) != 82){
        printf("getFinish() test #3 failed. \n");
    }
    if (getFinish(A, 42) != 78){
        printf("getFinish() test #4 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 64) != 128){
        printf("getFinish() test #5 failed. \n");
    }
    if (getFinish(A, 63) != 118){
        printf("getFinish() test #6 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 65) != 72){
        printf("getFinish() test #7 failed. \n");
    }
    if (getFinish(A, 1) != 200){
        printf("getFinish() test #8 failed. \n");
    }
    printf("getFinish() test passed \n");
    freeGraph(&A);
    freeList(&L);
return(0);
}
