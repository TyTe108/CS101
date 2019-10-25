#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "List.h"

typedef struct EntryObj* Entry;
typedef struct MatrixObj* Matrix;

struct MatrixObj{
    List* a;
};

#endif //MATRIX_H
