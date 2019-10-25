#include <stdlib.h>
#include "Matrix.h"

typedef struct EntryObj{
  int _i;
  double _d;
}EntryObj;

Entry newEntry(int i, double d) {
    Entry temp = malloc(sizeof(EntryObj));
    temp->_i = i;
    temp->_d = d;
    return temp;
}

void freeEntry(Entry* eN) {
    if( eN!=NULL && *eN!=NULL ){
        free(*eN);
        *eN = NULL;
    }
}

Matrix newMatrix(int n){
  Matrix M = (struct MatrixObj *) malloc(sizeof(struct MatrixObj)); //Dynamic Memory #1
  M->_n = n;
  M->_nnz = 0;
  M->_a = NULL;
  
  M->_a = malloc(sizeof(List) * n);  //Dynamic Memory #2
  
  //Just in case
  int i = 0;
    for (i = 0; i<n; i++){
        (M->_a)[i] = newList(); //same as *(a+i) //Dynamic Memory #3
    }
  return M;
}


void freeMatrix(Matrix* pM){
  Matrix M = *pM;
  int n = M->_n;
  for (i = 0; i<n; i++){
    freeList((M->_a)[i]); //same as *(a+i) //Dynamic Memory #3
  }
  M->_n = 0;
  M->_nnz = 0;
  free(M->_a); //Dynamic Memory #2
  M->_a = NULL;
  free(*pM); //Dynamic Memory #1
  *pM = NULL;
}



