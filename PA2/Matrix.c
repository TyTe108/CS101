#include <stdlib.h>
#include "Matrix.h"

typedef struct EntryObj{
  int _i;
  double _d;
}EntryObj;

Entry newEntry(int i, double d) {
    Entry temp = malloc(sizeof(EntryObj)); //Dynamic Memory #4
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

int size(Matrix M){
  return (M->_n);
}

int NNZ(Matrix M){
  return (M->_nnz);
}

int equals(Matrix A, Matrix B){
  if ((A->_n) != (B->_n) || (A->_nnz) != (B->_nnz)){
    return 0;
  }else{
    //COME BACK LATER: TAKE CARE OF COMPARISON
    
    return 1;
  }
}

void makeZero(Matrix M){
  
}

// changeEntry()
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x){
  //Error handling
  if(i < 1){
    printf("Error: calling changeEntry(Matrix M, int i, int j, double x) function on i < 1. \n");
    return;
  }
  if(j < 1){
    printf("Error: calling changeEntry(Matrix M, int i, int j, double x) function on j < 1. \n");
    return;
  }
  int s = size(M);
  if(i > s){
    printf("Error: calling changeEntry(Matrix M, int i, int j, double x) function on i > size of M. \n");
    return;
  }
  if(j > s){
    printf("Error: calling changeEntry(Matrix M, int i, int j, double x) function on j > size of M. \n");
    return;
  }
  //============
  List targetList = (M->_a)[i];
  //Iterate through the list
  moveFront(targetList);
  
  //If List is empty...
  if(length(targetList) == 0){
    Entry insertThis = newEntry(j, x); //Might need to keep track of this?...
    append(targetList,insertThis); 
  }else{
    //Loop through list to find the entry
    int repeat = 1;
    while(repeat == 1){ //Loop through List
      Entry currentEntry = get(targetList);
      int entryCol = currentEntry->_i;
      
      
      
      
    }
    
  }
  //if not empty
  
}



