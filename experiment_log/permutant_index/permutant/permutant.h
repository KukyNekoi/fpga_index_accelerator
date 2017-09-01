#ifndef PERMUTANT_H_
#define PERMUTANT_H_

#include <inttypes.h>
#include "../constants.h"
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

permutant_t* pcreate(size_t size);
permutant_t* pload(char *filename, size_t size);
permutant_t* pget(permutant_t *index, size_t offset);
permutant_t* pcreates();
permutant_t* invert_permutation(permutant_t *target);
permutant_t* pgetinvert(permutant_t *index, size_t offset);

permutant_distance_t pspearman_rho(permutant_t *index, size_t offset,  permutant_t *inverted_permutation);
permutant_distance_t pspearman_footrule(permutant_t *index, size_t offset, permutant_t *inverted_permutation);

void pcpy(permutant_t *dest, permutant_t *src);
void pfree(permutant_t *target);
void pprint(permutant_t *target, size_t offset);

#include "permutant.c"
#endif