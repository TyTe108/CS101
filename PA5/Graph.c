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
    G->source = NIL;
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
    if ((u > G->vertices) | (u <= 0)){
        printf("Error: Calling getParent() on an invalid vertices \n");
        return NIL;
    }
    if(G->parents == NULL){
        //printf("PARENTS ARE NULL \n");
        return NIL;
    }
    return (G->parents[u]);

}

int getDist(Graph G, int u){    
    if (G->source <= 0){
        return INF;
    }
 
    if ((u > G->vertices) | (u <= 0)){
        printf("Error: Calling getDist() on an invalid vertices \n");
        return INF;
    }
    if(G->distFromSource == NULL){
        return INF;
    }
    return (G->distFromSource[u]);
}

void getPath(List L, Graph G, int u){
    if (getSource(G) == NIL){
        return;
    }
     if ((u > G->vertices) | (u <= 0)){
        printf("Error: Calling getPath() on an invalid vertices \n");
        return;
    }
    if (u == getSource(G)){
        append(L, getSource(G));
    }else if (G->parents[u] == NIL){
        append(L, NIL);
    }else{
        getPath(L, G, G->parents[u]);
        append(L, u);
    }
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

    if ((u >= G->vertices) | (v >= G->vertices) | (u <= 0) | (v <= 0)){
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
    if ((u >= G->vertices) | (v >= G->vertices) | (u <= 0) | (v <= 0)){
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
    //Check if source s is valid
        if ((s >= G->vertices) | (s <= 0)){
        printf("Error: Calling BFS() on an invalid vertex s as source \n");
        return;
    }
    
    int n = G->vertices;
    G->source = s;
    
    //Allocating memory 
    if(G->color != NULL){
        free(G->color);
    }
    G->color = NULL; //Not necessary but..
    G->color = malloc((n+1) *  sizeof(int));
    
    if(G->distFromSource != NULL){
        free(G->distFromSource);
    }
    G->distFromSource = NULL; //Not necessary but..
    G->distFromSource = malloc((n+1) *  sizeof(int));
    
    if(G->parents != NULL){
        free(G->parents);
    }
    G->parents = NULL; //Not necessary but..
    G->parents = malloc((n+1) *  sizeof(int));
    
    for (int i = 1; i<=n; i++){
        G->color[i] = -1; //-1 white    0 gray  1 black
        G->distFromSource[i] = -1; //-1 infinity
        G->parents[i] = NIL;   
    }
    
    G->color[s] = 0; //-1 white    0 gray  1 black
    G->distFromSource[s] = 0; //-1 infinity
    G->parents[s] = NIL;   
    
    List Q = newList(); //A Queue
    append(Q,s);
    while(length(Q) > 0){
        int u = front(Q);
        deleteFront(Q); 
        for (moveFront(G->a[u]); index(G->a[u])>=0; moveNext(G->a[u])){ //
            int v = -1;
            if(length(G->a[u]) > 0){
                v=get(G->a[u]);
                
                if (G->color[v] == -1){
                G->color[v] = 0; //Gray
                G->distFromSource[v] = (G->distFromSource[u]) + 1;
                G->parents[v] = u;
                append(Q, v);
                }
            }
        }
        G->color[u] = 1; //Black
    }
    freeList(&Q);
}


Graph transpose(Graph G){
    int v = getOrder(G);
    Graph tranp = newGraph(v);
    
    for (int i = 1; i <= v; i++){
        for (moveFront(G->a[i]; index(G->a[i]) >= 0; moveNext(G->a[i])){
            if((length(G->a[i]) > 0){
                int j = get(G->a[i]);
                addEdge(tranp, j, i);
            }
        }
    }
}

void printGraph(FILE* out, Graph G){
    if(G->vertices == 0){
        fprintf(out, "ZERO VERTICES \n");
        return;
    }
    for(int i = 1; i<=G->vertices; i++){
        if(length(G->a[i]) > 0){
            fprintf(out, "%d: ", i);
            printList(out, G->a[i]);
            fprintf(out, "\n");
        }
    }
}
               
               
               
              
              
