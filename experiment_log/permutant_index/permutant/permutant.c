#ifndef PERMUTANT_C_
#define PERMUTANT_C_

#include "permutant.h"

typedef unsigned :BITS_PER_PERMUTATION permutant_t;

typedef struct permutation {
    // size_t size;
    permutant_t *permutants;
} permutation_t;

permutation_t create_permutation(/* size_t size */){
    permutation_t *obj = (permutation_t *) malloc(sizeof(permutation_t));
    obj->permutants = (permutant_t *) malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    // obj->size = size;
    return obj;
}

void destroy_permutation(permutation_t *target){
    free(target->permutants);
    free(target);
}

#endif