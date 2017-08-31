#ifndef VECTOR_H_
#define VECTOR_H_

#include <inttypes.h>

#ifndef VECTOR_SIZE
#define VECTOR_SIZE 8
#endif
typedef float vector_t;

// Moves pointer at specific offset based on VECTOR_DIM
#define VECTOR_AT(X, Y) ( X + (Y*VECTOR_SIZE) ) 

#include "vector.c"
#endif