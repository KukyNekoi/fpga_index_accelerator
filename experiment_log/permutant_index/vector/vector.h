#ifndef VECTOR_H_
#define VECTOR_H_

#include <inttypes.h>

#ifndef PERMUTATION_SIZE
#define PERMUTATION_SIZE 4
#endif
typedef double vector_t;

// Moves pointer at specific offset based on VECTOR_DIM
#define VECTOR_AT(X, Y) ( X + (Y*VECTOR_DIM) ) 

#include "vector.c"
#endif