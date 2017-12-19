#ifndef PERMUTANT_H_
#define PERMUTANT_H_

#include <stdlib.h>
#include <inttypes.h>
#include "../constants.h"

typedef struct {
    size_t dim;         // Dimensions of data for memory reshaping
    bool is_inverted;
    uint16_t *data;      // Data.
    uint16_t *inverted;  // Exists if there is an inverted index for this
} permutation_t;

typedef enum {
    spearman_rho,
    spearman_footrule
} permutation_distance_methods_t;

void permutation_init(permutation_t *permutation, size_t dim);
void permutation_set(permutation_t *permutation, size_t index, uint16_t value);
uint16_t permutation_get(permutation_t *permutation, size_t index);
void permutation_free(permutation_t *permutation);
void permutation_print(permutation_t *permutation);
size_t permutation_distance(permutation_t *a, permutation_t *b, permutation_distance_methods_t method);
void permutation_copy(permutation_t *dest, permutation_t *src);
bool _permutation_checkbounds(permutation_t *permutation, size_t index);
void _permutation_invert_if_not(permutation_t *permutation);

#endif