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

Graph newGraph(int n){
    Graph G = (struct GraphObj *) malloc(sizeof(struct GraphObj));
    G->vertices = n;
    G->edges = 0;
    
    G->a = M->_a = malloc((n+1) *  sizeof(List));  //Dynamic Memory #2; //An array of Lists whose ith element contains the neighbors of vertex i
    int i = 0;
    for (i = 1; i<=n; i++){
        (G->a)[i] = newList(); //same as *(a+i) //Dynamic Memory #3
    }
 
    G->color = malloc((n+1) * sizeof(int));
    G->parents = malloc((n+1) * sizeof(int));
    G->source = 0;
    G->distFromSource = malloc((n+1) * sizeof(int));
    
    return G;
}

void freeGraph(Graph* pG){
    Graph M = *pG;
    
    if (G == NULL){
    return;
  }
    int n = G->vertices;
    for (int i = 1; i<=n; i++){ 
        List freeThis = G->a[i];
        freeList(&freeThis); 
    }
    free(G->a);
    G->a= NULL;
    
    free(G->color);
    G->color = NULL;
    
    free(G->parents);
    G->parents = NULL;
    
    free(G->distFromSource);
    G->distFromSource = NULL;
    
    free(*pG );
    *pG = NULL;    
}

int getOrder(Graph G){
    return G->vertices;
}

int getSize(Graph G){
    return G->edges;
}

int getSource(Graph G){
    return G->source;
}

int getParent(Graph G, int u){
    if (u > G->vertices | u <= 0){
        printf("Error: Calling getParent() on an invalid vertices \n");
        return NIL;
    }
    if(G->a == NULL){
        return NIL;
    }
    return (G->a[u]);

}

