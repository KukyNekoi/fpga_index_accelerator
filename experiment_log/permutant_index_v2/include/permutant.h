#ifndef PERMUTANT_H_
#define PERMUTANT_H_

#include <inttypes.h>
#include "../constants.h"

typedef struct {
    size_t dim,         // Dimensions of data for memory reshaping
    bool inverted,
    uint16_t *data      // Data.
    uint16_t *inverted  // Exists if there is an inverted index for this
} permutation_t;

typedef enum {
    spearman_rho,
    spearman_footrule
} permutation_distance_methods_t

void permutation_init(permutation_t *dataset, size_t size, size_t dim);
void permutation_set(permutation_t *dataset, size_t permutation, permutation_t value);
uint16_t permutation_get(permutation_t *dataset, size_t permutation);
void permutation_free(permutation_t *dataset);
void permutation_print(permutation_t *dataset);
permutation_t permutation_distance(permutation_t *a, permutation_t *b, permutation_distance_methods_t method);
void permutation_copy(permutation_t *dest, permutation_t *src);
void permutation_free(permutation_t *target);

#endif