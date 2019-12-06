/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA4
 *========== */

#ifndef GRAPH_H
#define GRAPH_H


#include <stdio.h>
#include "List.h"


#define INF -1
#define NIL -2
#define UNDEF -3

typedef struct GraphObj* Graph;

struct GraphObj{
    List* a; //An array of Lists whose ith element contains the neighbors of vertex i
    int vertices;
    int edges;
    int* color;
    int* parents;
    int source;
    int* distFromSource;
    int* discover
    int* finish
};

/*** Constructors-Destructors ***/

//Function newGraph() returns a Graph pointing to a newly created GraphObj representing a graph having n vertices and no edges. 
Graph newGraph(int n);

//Function freeGraph() frees all dynamic memory associated with the Graph *pG, then sets the handle *pG to NULL. 
void freeGraph(Graph* pG);


/*** Access functions ***/

int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */

/* Manipulation procedures */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */

/*** Other operations ***/
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out, Graph G);
void visit(Graph G, int u, int* time);
void sortedFinishInsert(int* finish, List S, int v);

#endif //GRAPH_H
