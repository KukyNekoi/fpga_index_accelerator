#ifndef INDEXING_H_
#define INDEXING_H_

#include <inttypes.h>
#include "../constants.h"
#include "../dataset/dataset.h"
#include "../vector/vector.h"
#include "permutant.h"

typedef struct {
    size_t size,        // Actual size of the index
    size_t capacity,    // Current capacity of it
    size_t dim,         // Dimensions of data for memory reshaping
    uint16_t *data      // Data.
} index_t;


typedef struct {
    double sss_pivots,
    double sss_result_precision,
    double sss_sampling_factor,
    double sss_skip_factor,
    permutation_distance_methods_t permutation_distance_method,
    vector_distance_method_t vector_distance_method
} build_parameters_t

void index_init(index_t *index, size_t size, size_t dim);
void index_append(index_t *index, permutation_t value);
void index_set(index_t *index, size_t index, permutation_t value);
void index_double_capacity_if_full(index_t *index);
void index_free(index_t *index);
void index_print(index_t *index);
permutation_t index_get(index_t *index, size_t index);
index_t index_distance(index_t *index, size_t a, size_t b);
void index_copy(index_t *dest, index_t *src);
void index_free(index_t *target);

size_t comp (const void * elem1, const void * elem2);
vector_t get_sss_pivot_indices(index_t *index, double sampling_factor, double alpha);
vector_t force_sss_pivots(index_t *index, double sampling_factor, double precision, size_t amount);

void build(index_t *index, dataset_t *dataset, build_paramenters_t *params);

vector_t knn(index_t *index, dataset_t *dataset, element_t target, size_t k);
vector_t range_query(index_t *index, dataset_t *dataset, element_t target, double range);

#include "indexing.c"
#endif