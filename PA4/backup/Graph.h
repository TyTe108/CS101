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

typedef struct GraphObj* Graph;

struct GraphObj{
    List* a; //An array of Lists whose ith element contains the neighbors of vertex i
    int vertices;
    int edges;
    int* color;
    int* parents;
    int source;
    int* distFromSource;
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
/*** Other operations ***/
void printGraph(FILE* out, Graph G);

#endif //GRAPH_H
