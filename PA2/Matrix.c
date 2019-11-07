/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA2
 *========== */

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
  
  M->_a = malloc((n+1) *  sizeof(List));  //Dynamic Memory #2
  
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

  makeZero(*pM);

  int n = M->_n;
  for (int i = 1; i<=n; i++){
    List freeThis = M->_a[i];
    freeList(&freeThis); //same as *(a+i) //Dynamic Memory #3
  }
  M->_n = 0;
  M->_nnz = 0;


  free(M->_a); //Dynamic Memory #2
  M->_a= NULL;


  free(*pM ); //Dynamic Memory #1
  *pM = NULL;
}

int size(Matrix M){
  return (M->_n);
}

int NNZ(Matrix M){
  return (M->_nnz);
}

int equals(Matrix A, Matrix B){
  if(A == B){
    return 1;
  }
  if ((A->_n) != (B->_n) || (A->_nnz) != (B->_nnz)){
    return 0;
  }
  int n = size(A);
  for (int i = 1; i <= n; i++){
    List AL = A->_a[i];
    List BL = A->_a[i];
    if(length(AL)!= length(BL)){
      return 0;
    }
    else{
      if(length(AL) > 0 && length(BL) > 0){
	for(moveFront(AL),moveFront(BL); index(AL) >= 0 && index(BL)>=0; moveNext(AL), moveNext(BL)){
	  Entry AEntry = get(AL);
	  Entry BEntry = get(BL);
	  int equal = EntryEqual(AEntry, BEntry);
	  if (equal == 0){
	    return 0;
	  }
	}
      }
    }
  }
  return 1;
}



void makeZero(Matrix M){
  int n = M->_n;
  for (int i = 1; i <= n && NNZ(M)>0; i++){ 
    List L = M->_a[i];
    
    //nnz related fix, need to use delete from List
    if (length(L)> 0){
      for(moveFront(L); index(L)>= 0; moveNext(L)){
	Entry e = get(L);
	freeEntry(&e);
	M->_nnz--;
      }
    }
    clear(L);
  }
  
}


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
  /* int indexB4Insertion  = index(targetList); */
  /* printf("Index Before Insertion: %d\n", indexB4Insertion); */
  


  //If List is empty...
  if(length(targetList) == 0){
    //printf("Entering new row...\n");
    if(x != 0){
      Entry insertThis = newEntry(j, x);  //Might need to keep track of this?...
      append(targetList,insertThis); 
      (M->_nnz)++; //Keeping track of non-zero elements
    }
  }
  else{
    moveFront(targetList);
    //Loop through list to find the entry
    int repeat = 1;
    while(repeat == 1){ //Loop through List
      Entry currentEntry = get(targetList); // Might want to keep track of this
      int entryCol = currentEntry->_i;
      if (j == entryCol){
	if(x == 0){
	  delete(targetList);
	  (M->_nnz)--;
	}else{
	  currentEntry->_d = x; //Simply replace the (double element) if col already exists
	}
	repeat = 0; //Stop the loop
      }
      else if(j<entryCol){
	if(x != 0){
	  Entry insertThis = newEntry(j, x);
	  insertBefore(targetList, insertThis);
	  (M->_nnz)++; //Keeping track of non-zero elements
	}
	repeat = 0;
      }
      else{
	int ind = index(targetList);
	if(ind == length(targetList)-1){
	  if(x != 0){
	    Entry insertThis = newEntry(j, x); //Dynamic created, keep track for leaks
	  //....
	    append(targetList, insertThis);
	    (M->_nnz)++; //Keeping track of non-zero elements
	  }
	  repeat = 0;
	}
	else{
	  repeat = 1;
	  moveNext(targetList);
	}
      }
    }
  }

  //int indexAfterInsertion  = index(targetList);
  //printf("Index After Insertion: %d\n", indexAfterInsertion);
  
}

// Matrix Arithmetic operations ------------------------
// copy()
// Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A){
	int n = size(A);
	Matrix M = newMatrix(n);
	for (int i = 1; i<=n; i++){
	  List L = A->_a[i];
	  if(length(L)!= 0){
	    for(moveFront(L); index(L)>=0; moveNext(L)){
	    Entry e = get(L);
	    int entryCol = e->_i;
	    double entryVal = e->_d;
	    changeEntry(M, i, entryCol, entryVal);
	    }
	  }
	}
	return M;
}

Matrix transpose(Matrix A){
  Matrix M = newMatrix(size(A));
  int n = size(A);
  for (int i = 1; i<=n; i++){
    List L = A->_a[i];
    if (length(L)!= 0){
      for(moveFront(L); index(L)>=0; moveNext(L)){
	Entry e = get(L);
	int entryCol = e->_i;
	double entryVal = e->_d;
	changeEntry(M, entryCol, i, entryVal);
      }
    }
  }
  return M;
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
    printf("WARNING: Calling Matrix aum(Matrix A, Matrix B) when one of the matrices is empty\n");  
    return NULL;
  }
  
  if(A == B){
    Matrix M = scalarMult(2, A);
    return M;
  }

  int i = 1;
  int j = 1;
  List* AL = A->_a;
  List* BL = B->_a;
  
  int Annz = A->_nnz;
  int Bnnz = B->_nnz;
  Matrix M = newMatrix(An);


  //Make sure to set every index in the front before anything, index might be all
  //over the places

  for(int k = 1; k <= An; k++){
    if(length(AL[k]) > 0){
  	moveFront(AL[k]);
    }
    if(length(BL[k])> 0){
  	moveFront(BL[k]);
      }
  }      
  
  

  while (Annz > 0 || Bnnz > 0){ //Will stop the moment non zero elements in both Matrix are summed
    // printf("ANNZ is: %d \n", Annz);
    // printf("BNNZ is: %d \n", Bnnz);
  		Entry entryA = NULL;
  		Entry entryB = NULL;
		
  		if (length(AL[i]) > 0 && Annz > 0){ //Don't bother to get when Annz is already 0, meaning no more non-zero element
		  //to obtain from
		  //printf("A is not empty \n");
		  // printf("Index of A in the beginning is: %d\n", index(AL[i]));
  		  /* if(index(AL[i])<0){ */
  		  /*   moveFront(AL[i]); // Move cursor to the front if it's never initialized */
  		  /* } */
  		  entryA = get(AL[i]);
  		}
  		if (length(BL[j]) > 0 && Bnnz > 0){ //same explanation as AL above
		  // printf("B is not empty \n");
		  //printf("Index of B in the beginning is: %d\n", index(BL[j]));
		  /* if(index(BL[j])<0){ */
  		  /*   moveFront(BL[j]); // Move cursor to the front if it's never initialized */
  		  /* } */
		  entryB = get(BL[j]);
		  //printf("BVal in begin: %.1f \n", entryB->_d);
  		}
  		//Both are NULL
  		if (entryA == NULL && entryB == NULL){
  		  i++; //Can be more efficient by preventing increment when nnz is already 0
  		  j++;
		  // printf("Both entryA && entryB == NULL \n");
		  //printf("%d \n", i);
  		}else if(entryA == NULL && entryB != NULL){ //A is NULL B is not
  		  i++;
  		  int BCol = entryB->_i;
  		  double BVal = entryB ->_d;
  		  changeEntry(M, j, BCol, BVal);
  		  Bnnz--;
		  
  		  if(index(BL[j]) < length(BL[j])-1){
  		    moveNext(BL[j]); //Next entry in the list
  		  }else{
  		    j++; //End of list, next one in the array
  		  }
		  //printf("entryA == NULL && entryB ==NULL  \n");
	   
  		}else if (entryA != NULL && entryB == NULL){//B is NULL, A is not
  		  j++;
  		  int ACol = entryA->_i;
  		  double AVal = entryA->_d;
  		  changeEntry(M, i, ACol, AVal);
  		  Annz--;
  		  if(index(AL[i]) < length(AL[i])-1){
  		    moveNext(AL[i]); //Next entry in the list
  		  }else{
  		    i++; //End of list, next one in the array
  		  }
		  // printf("entryA != NULL && entryB == NULL  \n");
                                                 
  		}
		else if(entryA != NULL && B != NULL){ //Both are not NULL, meaning there are entries, I think most of the time this happens
		  //Check if they are in the same coloumn and row
		 

		  if (i == j){ //i & j are rows
		    int ACol = entryA->_i;
		    int BCol = entryB->_i;
		    //printf(" ACol:%d  BCol:  %.d\n", ACol, BCol);
		  
		    if (ACol == BCol){
		      //printf(" ACol:%d ==  BCol:  %.d\n", ACol, BCol);
		      double AVal = entryA->_d;
		      double BVal = entryB->_d;
		      double sum = AVal + BVal;
		    
		      // printf("%.1f + %.1f\n", AVal, BVal);

		      changeEntry(M, i,BCol,  sum);
		      
		      Annz--;
		      Bnnz--;
		      
		      if(index(AL[i]) < length(AL[i])-1){
			moveNext(AL[i]); //Next entry in the list
		      }else{
			i++; //End of list, next one in the array
		      }
		      if(index(BL[j]) < length(BL[j])-1){
			moveNext(BL[j]); //Next entry in the list
		      }else{
			j++; //End of list, next one in the array
		      }
		      //printf("ROWS AND COLS ARE == all around Row: %d, Col: %d \n ", i, ACol);
		    }else if(ACol > BCol){
		      //printf("ACol:%d >   BCol:  %.d\n", ACol, BCol);
		      
		      int BCol = entryB->_i;
		      double BVal = entryB->_d;
		      changeEntry(M, j, BCol,  BVal); 
		      Bnnz--;
		      
		      if(index(BL[j]) < length(BL[j])-1){
			moveNext(BL[j]); //Next entry in the list
		      }else{
			j++; //End of list, next one in the array
		      }
		      //printf("Same row but different col where ACol > BCol  \n");
		    }else if (ACol < BCol){
		      //printf("ACol:%d <  BCol:  %.d\n", ACol, BCol);
		      int ACol = entryA->_i;
		      double AVal = entryA->_d;
		      changeEntry(M, i, ACol, AVal);
		      Annz--;


		      if(index(AL[i]) < length(AL[i])-1){
			moveNext(AL[i]); //Next entry in the list
		      }else{
			i++; //End of list, next one in the array
		      }
		      // printf("Same row but different col where ACol <  BCol  \n");
		    }


		  }else if(i<j){ //Means A is behind, so B is probably empty or reached the end
		    int ACol = entryA->_i;
		    double  AVal = entryA->_d;
		    changeEntry(M, i, ACol, AVal);
		    Annz--;

		    if(index(AL[i]) < length(AL[i])-1){
		      moveNext(AL[i]); //Next entry in the list
		    }else{
		      i++; //End of list, next one in the array
		    }
		  }else if (i>j){ //Means B is behind, so A is probably empty or reached the end
		    int BCol = entryB->_i;
		    double  BVal = entryB->_d;
		    changeEntry(M, j, BCol, BVal);
		    Bnnz--;
		    		    
		    if(index(BL[j]) < length(BL[j])-1){
		      moveNext(BL[j]); //Next entry in the list
		    }else{
		      j++; //End of list, next one in the array
		    }
		    
		  }
		     
  		}
  }
  return M;
		
}


Matrix diff(Matrix A, Matrix B){
    //check precondition:
  int An = size(A);
  int Bn = size(B);
  if (An != Bn){
    printf("Error: Calling Matrix diff(Matrix A, Matrix B) when one of the matrices is empty\n");  
    return NULL;
  } 

  if(A == B){
    Matrix M = newMatrix(An);
    return M;
  }

  if(A->_nnz == 0){
    Matrix M = scalarMult(-1, B);
    return M;
  }

  Matrix BNeg = NULL;
  Matrix M;
  
  BNeg = scalarMult(-1, B);
  M = sum(A, BNeg);
  freeMatrix(&BNeg);
  return M;
}

Matrix product(Matrix A, Matrix B){
  //check precondition:
  int An = size(A);
  int Bn = size(B);
  if (An != Bn){
    printf("Error: Calling Matrix aum(Matrix A, Matrix B) when one of the matrices is empty\n");  
    return NULL;
  } 
  //printf("THIS WENT THROUGH HERE \n");

  int i = 1;
  int j = 1;
  //int k = 1;

  Matrix M = newMatrix(An);

  Matrix Bt = transpose(B); //Free it later, malloc

  //printf("Matrix Bt in Prod: \n");
  //printMatrix(stdout, Bt);
 
  
  List AL = A->_a[i];
  List BtL = Bt->_a[j];
  int Annz = NNZ(A);
  //int Bnnz = NNZ(Bt);

  // printf("Inside Product Print: \n");
  //printMatrix(stdout, A);

  while(i<=size(A) && (Annz > 0)){
    AL = A->_a[i];
    j = 1;
    while(j<=size(Bt)){
      BtL = Bt->_a[j];
      
      double dotProd = vectorDot(AL, BtL);
      //printf("%.1f ", dotProd);
      changeEntry(M, i, j, dotProd);
      j++;
      //printf("%d \n",i*j);
    }
    i++;
    Annz = Annz - length(AL);
    //printf("%d \n", i);
  }
  freeMatrix(&Bt);
  //printMatrix(stdout, M);

  //printf("M inside: \n");
  return M;
}


// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows
// are not printed. Each non-zero is represented as one line consisting
// of the row number, followed by a colon, a space, then a space separated
// list of pairs "(col, val)" giving the column numbers and non-zero values
// in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M){
  if(M->_nnz == 0){
    //fprintf(out, "ZERO MATRICES \n");
    return;
  }

  int n = (M->_n);
  for (int i = 1; i<=n; i++){  
    List L = M->_a[i];
    if(length(L) != 0){ //do not approach an empty list
      fprintf(out, "%d: ", i);
      for(moveFront(L); index(L)>=0; moveNext(L)){
	Entry thisEntry = get(L);
	int entryColVal = thisEntry->_i;
	double entryElemVal = thisEntry->_d;
  
	//	if(entryElemVal != 0){ //only print non-zero elements
	  fprintf(out, "(");
	  fprintf(out, "%d, ", entryColVal);
	  fprintf(out, "%.1f", entryElemVal);
	  fprintf(out, ") ");
	  //	}
      }
      fprintf(out, "\n");
    }
    //printf("%d \n", i);
  }
}

Entry  getEntry(Matrix M, int row, int col){

  //Precondition check  
  int n = size(M);
  if(row > n || col > n || row < 1 || col < 1){   
    printf("Error: Calling getEntry() when either row or col is greater or less than 1 \n");
    return NULL;
  }
  if (M == NULL){
    printf("Error: Calling getEntry() when Matrix M is NULL \n");
    exit(1);
  }

  List L = M->_a[row];
  
  if (length(L)!= 0){
    for (moveFront(L); index(L)>=0; moveNext(L)){
      Entry e = get(L);
      int eCol = e->_i;
      if (eCol == col){
	return e;
      }
    }
    //End of List, no such entry found
    // printf("Error: No such non zero row and col found \n");
  }
  return NULL;
}

double vectorDot(List P, List Q){
  double k = 0;
  if(length(P) <= 0 || length(Q) <= 0){
    return k;
  }
  //printf("CALLED... \n ");

  if(length(P) != 0){
    moveFront(P);
  }
  if (length(Q) != 0){
    moveFront(Q);
  }

  //Move the smaller index
  while(index(P) >= 0 &&  index(Q) >= 0){
    Entry PEntry = get(P);
    Entry QEntry = get(Q);
    double i = PEntry->_d;
    double j = QEntry->_d;
    int PCol = PEntry->_i;
    int QCol = QEntry->_i;
    
    // printf("P: \n");
    // printf("P Col: %d P Val: %.1f \n", PCol, i);
    // printf("Q: \n");
    //printf("Q Col: %d Q Val: %.1f \n\n\n", QCol, j);

    if(PCol == QCol){
      k = k + ( i * j);
      moveNext(P);
      moveNext(Q);
      
      // printf("%.1f, %.1f   ", i, j);
    }else if(PCol > QCol){

      // printf("%.1f, %.1f   ", i, j);
      moveNext(Q);
    }else{
      
      // printf("%.1f, %.1f   ", i, j);
      moveNext(P);
    }
  }
  return k;
}

int EntryEqual(Entry A, Entry B){
  int ACol = A->_i;
  int BCol = B->_i;
 
  double AVal = A->_d;
  double BVal = B->_d;

  if(ACol == BCol && AVal == BVal){
    return 1;
  }
  return 0;
}
