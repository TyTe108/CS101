/*==========
 * Tyler Te
 * CruzID: tylim
 * Assignment: PA1
 * ==========*/

#include <stdlib.h>
#include "List.h"


typedef struct NodeObj{
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

Node newNode(int data) {
    Node temp = malloc(sizeof(NodeObj));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void freeNode(Node* pN) {
    if( pN!=NULL && *pN!=NULL ){
        free(*pN);
        *pN = NULL;
    }
}

//List Constructor & Destructor

List newList(void){
	List L = (struct ListObj *) malloc(sizeof(struct ListObj));
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	L->cursor = NULL;
	L->cursorIndex = -1;
	return(L);  
}

void freeList(List* pL){
	clear(*pL);
	free(*pL);
}

//Access Functions
//================================

int length(List L){
	return (L->length);
} // Returns the number of elements in L.

int index(List L){
	return (L->cursorIndex);
} // Returns index of cursor element if defined, -1 otherwise.

int front(List L){
	if(length(L) <= 0){
		printf("List Error: calling Front(List L) on an empty List\n");
		exit(1);
	}	
	return (L->head->data);
}

int back(List L){
	if(length(L) <= 0){  
                printf("List Error: calling Back(List L) on an empty List\n");                                                     
		exit(1); 
       }
	return (L->tail->data);
}


int get(List L){
	if (index < 0 ){
		printf("List Error: calling get(List L) on a negative index\n");
		exit(1);				
	}
	if (length(L)<=0){
		printf("List Error: calling get(List L) on an empty List\n PS: Why is index not negative then?\n");
		exit(1);
	}

	return (L->cursor->data);

}

int equals(List A, List B){
    	Node a = front(A);
    	Node b = front(B);

    	if( A==NULL || B==NULL ){
        	printf("List Error: calling equals() on NULL List reference\n PS: How did it pass the front tests then?..\n");
        	exit(1);
    	}

	while (a != NULL || b != NULL){
		if (a != b){
			return 0;
		}
		a = a->next;
		b = b->next;
	}

	return(1);
		
}


//-------------------------------
void clear(List L){

}

void append(List L, int data){


}

void insertAfter(List L, int data){


}

                           
