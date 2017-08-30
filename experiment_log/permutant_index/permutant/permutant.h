#ifndef PERMUTANT_H_
#define PERMUTANT_H_

// Defines permutation size, pretty much like defining the number of dimensions
// The idea is to reduce permutant size as much as possible by using 
// log2(dimension) as the integer length.
#define PERMUTATION_SIZE 512
#define BITS_PER_PERMUTATION 9

#include "permutant.c"
#endif