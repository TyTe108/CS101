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
        printf("DG getSize() #1 test failed. \n");
    }
    
    addArc(A, 54, 1);
    addArc(A, 54, 2);
    addArc(A, 54, 3);
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    if (getSize(A) != 5){
        printf("DG getSize() #2 test failed. \n");
    }
    for (int i = 1; i <= 100; i++) {
        append(L, i);
    }
    DFS(A, L);
    if (getSize(A) != 5){
        printf("DG getSize() #3 test failed. \n");    
    }
    addArc(A, 55, 1);
    if (getSize(A) != 6){
        printf("DG getSize() #3 test failed. \n");    
    }
    printf("DG getSize() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //DG_getParent============================
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getParent(A, i) != NIL){
            printf("DG getParent() test #1 failed. \n");   
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
        printf("DG getParent() test #2 failed. \n");   
    }
    if (getParent(A, 2) != NIL){
        printf("DG getParent() test #3 failed. \n");   
    }
    if (getParent(A, 42) != 3){
        printf("DG getParent() test #4 failed. \n");   
    }
    if (getParent(A, 3) != 64){
        printf("DG getParent() test #5 failed. \n");   
    }
    if (getParent(A, 4) != 64){
        printf("DG getParent() test #6 failed. \n");   
    }
    printf("DG getParent() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //DG_getDiscover============================

    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
          if (getDiscover(A, i) != UNDEF){
             printf("DG getDiscover() test #1 failed. \n");   
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
        printf("DG getDiscover() test #2 failed. \n");
    }
    
    printf("Print the Graph: \n");
    printGraph(stdout, A);
    
    printf("DG getDiscover() of v 64 is %d\n", getDiscover(A, 64));
    if (getDiscover(A, 64) != 73){
        printf("DG getDiscover() test #3 failed. \n");
    }
    if (getDiscover(A, 4) != 80){
        printf("DG getDiscover() test #4 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 4) != 126){
        printf("DG getDiscover() test #5 failed. \n");
    }
    if (getDiscover(A, 63) != 117){
        printf("DG getDiscover() test #6 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 65) != 71){
        printf("DG getDiscover() test #7 failed. \n");
    }
    if (getDiscover(A, 1) != 199){
        printf("DG getDiscover() test #8 failed. \n");
    }
    printf("DG getDiscover() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //DG_getFinish============================
    
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getFinish(A, i) != UNDEF){
            printf("DG getFinish() test #1 failed. \n");   
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
        printf("DG getFinish() test #2 failed. \n");
    }
    if (getFinish(A, 64) != 82){
        printf("DG getFinish() test #3 failed. \n");
    }
    if (getFinish(A, 42) != 78){
        printf("DG getFinish() test #4 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 64) != 128){
        printf("DG getFinish() test #5 failed. \n");
    }
    if (getFinish(A, 63) != 118){
        printf("DG getFinish() test #6 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 65) != 72){
        printf("DG getFinish() test #7 failed. \n");
    }
    if (getFinish(A, 1) != 200){
        printf("DG getFinish() test #8 failed. \n");
    }
    printf("DG getFinish() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //UG_getSize============================
    
    A = newGraph(100);
    L = newList();
    
    if (getSize(A) != 0){
        printf("UG getSize() test #1 failed. \n");
    }
    addEdge(A, 54, 1);
    addEdge(A, 54, 2);
    addEdge(A, 54, 3);
    addEdge(A, 1, 55);
    if (getSize(A) != 4){
        printf("UG getSize() test #2 failed. \n");
    }
    for (int i = 1; i <= 100; i++) {
        append(L, i);
    }
    DFS(A, L);
    if (getSize(A) != 4){
        printf("UG getSize() test #3 failed. \n");
    }
    addEdge(A, 1, 56);
    if (getSize(A) != 5){
        printf("UG getSize() test #4 failed. \n");
    }
    
    printf("UG getSize() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //UG_getParent============================
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getParent(A, i) != NIL){
            printf("UG getParent() test #1 failed. \n");
        }
    }
    addEdge(A, 64, 4);
    addEdge(A, 64, 3);
    addEdge(A, 42, 2);
    addEdge(A, 2, 64);
    addEdge(A, 4, 2);
    addEdge(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        append(L, i);
    }
    DFS(A, L);
    if (getParent(A, 100) != NIL){
        printf("UG getParent() test #2 failed. \n");
    }
    if (getParent(A, 2) != NIL){
        printf("UG getParent() test #3 failed. \n");
    }
    if (getParent(A, 42) != 3){
        printf("UG getParent() test #4 failed. \n");
    }
    if (getParent(A, 3) != 64){
        printf("UG getParent() test #5 failed. \n");
    }
    if (getParent(A, 4) != 2){
        printf("UG getParent() test #6 failed. \n");
    }
    
    printf("UG getParent() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //UG_getDiscover============================
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
        if (getDiscover(A, i) != UNDEF){
            printf("UG getDiscover() test #1 failed. \n");
        }
    }
    addEdge(A, 64, 4);
    addEdge(A, 64, 3);
    addEdge(A, 42, 2);
    addEdge(A, 2, 64);
    addEdge(A, 4, 2);
    addEdge(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        prepend(L, i);
    }
    DFS(A, L);
    if (getDiscover(A, 100) != 1){
        printf("UG getDiscover() test #2 failed. \n");
    }
    if (getDiscover(A, 64) != 73){
        printf("UG getDiscover() test #3 failed. \n");
    }
    if (getDiscover(A, 4) != 75){
        printf("UG getDiscover() test #4 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 4) != 121){
        printf("UG getDiscover() test #5 failed. \n");
    }
    if (getDiscover(A, 63) != 117){
        printf("UG getDiscover() test #6 failed. \n");
    }
    DFS(A, L);
    if (getDiscover(A, 65) != 71){
        printf("UG getDiscover() test #7 failed. \n");
    }
    if (getDiscover(A, 1) != 199){
        printf("UG getDiscover() test #8 failed. \n");
    }
    
    printf("UG getDiscover() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    //UG_getFinish============================
    A = newGraph(100);
    L = newList();
    
    for (int i = 1; i <= 100; i++){
          if (getFinish(A, i) != UNDEF){
              printf("UG getFinish() test #1 failed. \n");
          }
    }
    addEdge(A, 64, 4);
    addEdge(A, 64, 3);
    addEdge(A, 42, 2);
    addEdge(A, 2, 64);
    addEdge(A, 4, 2);
    addEdge(A, 3, 42);
    for (int i = 1; i <= 100; i++) {
        prepend(L, i);
    }
    DFS(A, L);
    if (getFinish(A, 100) != 2){
        printf("UG getFinish() test #2 failed. \n");
    }
    if (getFinish(A, 64) != 82){
        printf("UG getFinish() test #3 failed. \n");
    }
    if (getFinish(A, 42) != 80){
        printf("UG getFinish() test #4 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 64) != 128){
        printf("UG getFinish() test #5 failed. \n");
    }
    if (getFinish(A, 63) != 118){
        printf("UG getFinish() test #6 failed. \n");
    }
    DFS(A, L);
    if (getFinish(A, 65) != 72){
        printf("UG getFinish() test #7 failed. \n");
    }
    if (getFinish(A, 1) != 200){
        printf("UG getFinish() test #8 failed. \n");
    }
    
    printf("UG getFinish() test passed \n");
    freeGraph(&A);
    freeList(&L);
    
    return(0);
}
