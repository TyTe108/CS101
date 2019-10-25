#include <stdlib.h>
#include "Matrix.h"

typedef struct EntryObj{
  int _i;
  int _d;
}EntryObj;

Entry newEntry(int i, double d) {
    Entry temp = malloc(sizeof(EntryObj));
    temp->_i = i;
    temp->_d = d;
    return temp;
}
