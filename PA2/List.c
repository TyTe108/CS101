/*==========
 *Tyler Te
 *CruzID: tylim
 *Assignment: PA2
 *========== */

#include <stdlib.h>
#include "List.h"


typedef struct NodeObj{
    void* data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

Node newNode(void* data) {
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
    //L->cursorIndex = -1;
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
  // return (L->cursorIndex);
  int cursorIndex = 0;
  Node walker = L->head;

  if(L->cursor == NULL){
    return -1;
  }else{
    while(walker != L->cursor){
      if (walker == NULL){
	printf("Error calling index(List L): The cursor is not pointing to anything inside the List!\n");
      }
      
      cursorIndex = cursorIndex + 1;
      walker = walker->next;

    }
    return cursorIndex;
  }


} // Returns index of cursor element if defined, -1 otherwise.

void* front(List L){
    if(length(L) <= 0){
        printf("List Error: calling Front(List L) on an empty List\n");
	exit(1);
    }
    return (L->head->data);
}

void* back(List L){
    if(length(L) <= 0){
        printf("List Error: calling Back(List L) on an empty List\n");
        exit(1);
    }
    return (L->tail->data);
}


void* get(List L){
  int i = index(L);
    if (i < 0 ){
        printf("List Error: calling get(List L) on a negative index\n");
        exit(1);
    }
    if (length(L)<=0){
        printf("List Error: calling get(List L) on an empty List\n PS: Why is index not negative then?\n");
        exit(1);
    }

    return (L->cursor->data);

}

// Manipulation procedures ----------------------------------------------------
void clear(List L){
  if (L == NULL || L->head == NULL || L->tail == NULL){
    return;
  }
  while (L->head != NULL){
    deleteFront(L);
  }

}

void moveFront(List L){
    if (L->length <= 0){
        printf("Error: calling moveFront(List L) function on empty list. \n");
        exit(1);
    }
    L->cursor = L->head;
    // L->cursorIndex = 0;
}

void moveBack(List L){
    if (L->length <= 0){
        printf("Error: calling moveBack(List L) function on empty list. \n");
        exit(1);
    }
    L->cursor = L->tail;
    // L->cursorIndex = (L->length - 1);
}

void movePrev(List L){
    

  int cursorIndex = index(L);

    if (cursorIndex != -1 && cursorIndex != 0){ // If cursor is defined and not at front, move cursor one step toward the front
      //L->cursorIndex = (L->cursorIndex) - 1;
        L->cursor = (L->cursor)->prev;
    }
    else if(cursorIndex != -1 &&  cursorIndex == 0 ){ //if cursor is defined and at front, cursor becomes undefined
        //do nothing
        //L->cursorIndex = -1;
        L->cursor = NULL;
    }
}


void moveNext(List L){
    int cursorIndex = index(L);
    if (cursorIndex !=-1 && cursorIndex != (L->length -1)){
      //cursorIndex = (cursorIndex) + 1;
        L->cursor = (L->cursor)->next;
    }
    else if(cursorIndex != -1 &&  cursorIndex == (L->length -1) ){
      //L->cursorIndex = -1;
        L->cursor = NULL;
    }
} // If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
//  // back, cursor becomes undefined; if cursor is undefined
//   // do nothing

void prepend(List L, void* data){
  if(L->length == 0){
    Node prependThis = newNode(data); //Make a new node to the list
    L->head = prependThis;
    L->tail = prependThis;
    L->length++;
  }
  else  if(L->length > 0){ //
    Node saveCursor = L->cursor;
    moveFront(L); 
    insertBefore(L, data);
    L->cursor = saveCursor;   
  }
} 

void append(List L, void* data){
  if(L->length == 0){
    Node appendThis = newNode(data); //Make a new node to the list
    L->head = appendThis;
    L->tail = appendThis;
    L->length++;
  }else  if(L->length > 0){
    Node saveCursor = L->cursor; 
    moveBack(L); 
    insertAfter(L, data);
    L->cursor = saveCursor;
  }
}

void insertBefore(List L, void* data){
  if(length <= 0){
    printf("Calling insertBefore(List L, int data) function on an empty L.\n");
    return;
  }
  //What happens if cursor is undefined?...
  //if not undefined though
  if (L->cursor == NULL){
    printf("Calling insertBefore(List L, int data) function on NULL cursor.\n");
    return;
  }else{
    Node insertThis = newNode(data);
    Node prevHolder = (L->cursor) ->prev;
    insertThis-> prev = prevHolder;
    insertThis-> next = (L->cursor);
    if (prevHolder != NULL){
      prevHolder-> next = insertThis;
    }
    L->cursor->prev = insertThis;
    if (L->cursor == L->head){
      L->head = insertThis;
      }
    L->length++;
  }

}

void insertAfter(List L, void* data){
  if(length <= 0){
    printf("Calling insertBefore(List L, int data) function on an empty L.\n");
    return;
  }
  //What happens if cursor is undefined?...
  //if not undefined though
   if (L->cursor == NULL){
    return;
  }else{
     Node insertThis = newNode(data);  
     Node nextHolder = (L->cursor)->next;
     insertThis->prev = L-> cursor;
     insertThis ->next = nextHolder;
     (L->cursor)->next = insertThis;
     if(L->cursor == L->tail){
       L->tail = insertThis; //What if you are adding after a tail?
     }
     if (nextHolder != NULL){
       nextHolder-> prev = insertThis;
       // printf("This has been called \n);
     }
     L->length++; 
  }

  
  //what happens when
  
}

void deleteFront(List L){
  if (length(L)==0){
    printf("Calling deleteFront(List L) on an empty List Nani the fuck? \n");
    return;
  }

  if (L->head == L->tail){
    freeNode(&(L->tail));
    L->head = NULL;
    L->tail = NULL;
    L->length--;
    return;
  }

  //Node h = L->head;
  Node newHead = L->head-> next;

  //what if cursor is front? Do this...
  if (L->head == L->cursor){
    L->cursor = NULL;
  }

  freeNode(&(L->head));
  L->head = newHead;
  L->length--;


} // Delete the front element. Pre: length()>0
void deleteBack(List L){
  if (length(L)==0){
    printf("Calling deleteBack(List L) on an empty List Nani the fuck? \n");
    return;
  }
  if (L->head == L->tail){
     freeNode(&(L->tail));
     L->head = NULL;
     L->tail = NULL;
     L->length--;
     return;
  }
  
  //Node t = L->tail;
  Node newTail = L->tail -> prev;

  //what if cursor is back?
  if (L->tail == L->cursor){
    L->cursor = NULL;
  }

  //what if there's only 1 element left?
  freeNode(&(L->tail));
  L->tail = newTail;
  L->length--;

} // Delete the back element. Pre: length()>0


void delete(List L){
  if ((L == NULL) | (L->head == NULL)) {
    printf("List Error: calling Remove(Node removeThis, Node headPtr)) on NULL List reference\n");
    exit(1);
  }
  //when the node you are trying to delete is the last in the list, simply delete it, and return the item inside
  Node deleteThis = L->cursor;
  if(deleteThis == L->head){
    deleteFront(L);
  }
  else if(deleteThis == L->tail){
    deleteBack(L);
  }
  else{
    Node beforeCursor = deleteThis->prev;
    Node afterCursor = deleteThis ->next;
    
    freeNode(&deleteThis);
    beforeCursor->next = afterCursor;
    afterCursor->prev = beforeCursor;
    L->length--;
  }
}

// void printList(FILE* out, List L){
//    for (Node n = L->head; n != NULL; n = n-> next){
//     fprintf(out,"%d " , n->data);
//   }
//    //fprintf(out, "%d ",  front(L));
// }



//...
