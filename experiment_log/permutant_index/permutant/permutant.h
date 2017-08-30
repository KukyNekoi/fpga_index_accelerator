#ifndef PERMUTANT_H_
#define PERMUTANT_H_

#include <inttypes.h>

// Defines permutation size, pretty much like defining the number of dimensions
// The idea is to reduce permutant size as much as possible by using
// log2(dimension) as the integer length.
#ifndef PERMUTATION_SIZE
#define PERMUTATION_SIZE 4
#endif
typedef uint16_t permutant_t;
typedef uint16_t permutant_distance_t;

// Moves pointer at specific offset based on PERMUTATION_SIZE
#define INDEX_AT(X, Y) ( X + (Y*PERMUTATION_SIZE) ) 

#include "permutant.c"
#endif