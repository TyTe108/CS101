#include <stdlib.h>
#include "Matrix.h"
#include "List.h"

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
  
  M->_a = malloc(sizeof(List) *(n+1));  //Dynamic Memory #2
  
  //Just in case
  int i = 0;
    for (i = 1; i<=n; i++){
        (M->_a)[i] = newList(); //same as *(a+i) //Dynamic Memory #3
    }
  return M;
}


void freeMatrix(Matrix* pM){ 
  Matrix M = *pM;

  if (M == NULL){
    return;
  }

  int n = M->_n;
  for (int i = 1; i<=n; i++){
    List freeThis = M->_a[i];
    freeList(&freeThis); //same as *(a+i) //Dynamic Memory #3
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

  //If List is empty...
  if(length(targetList) == 0){
    //printf("Entering new row...\n");
    Entry insertThis = newEntry(j, x);  //Might need to keep track of this?...
    append(targetList,insertThis); 
    if(x != 0){
      (M->_nnz)++; //Keeping track of non-zero elements
    }
  }else{
    moveFront(targetList);
    //Loop through list to find the entry
    int repeat = 1;
    while(repeat == 1){ //Loop through List
      Entry currentEntry = get(targetList); // Might want to keep track of this
      int entryCol = currentEntry->_i;
      if (j == entryCol){
	currentEntry->_d = x; //Simply replace the (double element) if col already exists
	if(x != 0){
	  (M->_nnz)++; //Keeping track of non-zero elements
	}
	repeat = 0; //Stop the loop
      }else if(j<entryCol){
	Entry insertThis = newEntry(j, x);
	insertBefore(targetList, insertThis);
	if(x != 0){
	  (M->_nnz)++; //Keeping track of non-zero elements
	}
	repeat = 0;
      }else{
	Entry insertThis = newEntry(j, x); //Dynamic created, keep track for leaks
	int ind = index(targetList);
	if(ind == length(targetList)-1){
	  append(targetList, insertThis);
	  if(x != 0){
	    (M->_nnz)++; //Keeping track of non-zero elements
	  }
	  repeat = 0;
	}else{
	  repeat = 1;
	  moveNext(targetList);
	}
      }
    }
  }
}

// scalarMult()
// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A){

  if(A == NULL){
    printf("WARNING: Calling Matrix scalarMult(double x, Matrix A) on empty Matrix A\n");  
    return NULL;
  }

  int n = size(A);
  Matrix xA = newMatrix(n);
  for (int i = 1; i<=n; i++){
    List L = A->_a[i];
    if (length(L) != 0){
      for (moveFront(L); index(L)>= 0; moveNext(L)){
	Entry thisEntry = get(L);
	int entryColVal = thisEntry->_i;
	double entryElemVal = thisEntry->_d;
	//scale it
	entryElemVal = entryElemVal * x;
	changeEntry(xA, i, entryColVal, entryElemVal);
      }
    }
  }
  return xA;

}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B){
  //check precondition:
  int An = size(A);
  int Bn = size(B);
  if (An != Bn){
    printf("WARNING: Calling Matrix scalarMult(double x, Matrix A) on empty Matrix A\n");  
    return NULL;
  }
  
  int Annz = A->_nnz;
  int Bnnz = B->_nnz;

  if(Annz >= Bnnz){
    int i = 1; //For A
    int j = 1; //For B
    while (Annz > 0){
      List Al = A->_a[i];
      List Bl = B->_a[j];

      int ACol = get[Al];
      int BCol = get[Bl];

      //if i == j && ACol == BCol

      //......
    }

      
  }else{
	
    }
  }
}


// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows
// are not printed. Each non-zero is represented as one line consisting
// of the row number, followed by a colon, a space, then a space separated
// list of pairs "(col, val)" giving the column numbers and non-zero values
// in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M){
  int n = (M->_n);
  for (int i = 1; i<=n; i++){  
    List L = M->_a[i];

    if(length(L) != 0){ //do not approach an empty list
      fprintf(out, "%d: ", i);
      for(moveFront(L); index(L)>=0; moveNext(L)){
	
	Entry thisEntry = get(L);
	int entryColVal = thisEntry->_i;
	double entryElemVal = thisEntry->_d;
  
	if(entryElemVal != 0){ //only print non-zero elements
	  fprintf(out, "(");
	  fprintf(out, "%d, ", entryColVal);
	  fprintf(out, "%.1f", entryElemVal);
	  fprintf(out, ") ");
	}
      }
      fprintf(out, "\n");
    }
  }
}

