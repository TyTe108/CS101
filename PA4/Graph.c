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
    
    G->a = malloc((n+1) *  sizeof(List));  //Dynamic Memory #2; //An array of Lists whose ith element contains the neighbors of vertex i
    int i = 0;
    for (i = 1; i<=n; i++){
        (G->a)[i] = newList(); //same as *(a+i) //Dynamic Memory #3
    }
 
    G->color = NULL;
    G->parents = NULL;
    G->source = 0;
    G->distFromSource = NULL;
    
    return G;
}

void freeGraph(Graph* pG){
    Graph G = *pG;
    
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
    
    if(G->color != NULL){
        free(G->color);
        G->color = NULL;
    }
    
    if(G->parents != NULL){
        free(G->parents);
        G->parents = NULL;
    }
    
    if(G->distFromSource != NULL){
        free(G->distFromSource);
        G->distFromSource = NULL;
    }
    
    free(*pG);
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
    if(G->parents == NULL){
        return NIL;
    }
    return (G->parents[u]);

}

int getDist(Graph G, int u){
     if (u > G->vertices | u <= 0){
        printf("Error: Calling getParent() on an invalid vertices \n");
        return NIL;
    }
    if(G->distFromSource == NULL){
        return NIL;
    }
    return (G->distFromSource[u]);
}

void getPath(List L, Graph G, int u){


}


void makeNull(Graph G){
    if (G == NULL){
    return;
  }
    int n = G->vertices;
    for (int i = 1; i<=n; i++){ 
        List clearThis = G->a[i];
        clear(clearThis);
    }
    G->edges = 0;
    
    if(G->color != NULL){
        free(G->color);
        G->color = NULL;
    }
    
    if(G->parents != NULL){
        free(G->parents);
        G->parents = NULL;
    }
    
    if(G->distFromSource != NULL){
        free(G->distFromSource);
        G->distFromSource = NULL;
    }
}



void addEdge(Graph G, int u, int v){
    List L = NULL;
    int exist1 = 0;

    List M = NULL;
    int exist2 = 0;

    if (u >= G->vertices | v >= G->vertices | u <= 0 | v <= 0){
        printf("Error: Calling addEdge() on an invalid vertices \n");
        return;
    }
    
    //ADD V TO U's LIST
    L = (G->a)[u];
    exist1 = Search(L, v);
    M = (G->a)[v];
    exist2 = Search(M, u);
    
    if (exist1 == 1 && exist2 == 1){
        printf("Calling addEdge() function when edge already exists \n");
        return;
    }else{
        sortedInsert(L, v);
        sortedInsert(M, u);
        G->edges++;
    }
}

void addArc(Graph G, int u, int v){
    if (u >= G->vertices | v >= G->vertices | u <= 0 | v <= 0){
        printf("Error: Calling addArc() on an invalid vertices \n");
        return;
    }
    List L = (G->a)[u];
    int exist = Search(L, v);
    
    if (exist == 1){
        printf("Calling addArc() function when edge already exists \n");
        return;
    }else{
        sortedInsert(L, v);
        G->edges++;
    }
}

void BFS(Graph G, int s){
    for (int i = 1; i<=n; i++){
        
    
    }
}

void printGraph(FILE* out, Graph G){
    if(G->vertices == 0){
        fprintf(out, "ZERO VERTICES \n");
        return;
    }
    for(int i = 1; i<=G->vertices; i++){
        fprintf(out, "%d: ", i);
        if(length(G->a[i]) > 0){
            printList(out, G->a[i]);
        }
    }
}
               
               
               
              
              
