#ifndef INDEXING_C_
#define INDEXING_C_

#include "index.h"

void index_init(index_t *index, size_t size, size_t dim){
    return;
}
void index_append(index_t *index, permutation_t value){
    return;
}
void index_set(index_t *index, size_t index, permutation_t value){
    return;
}
void index_double_capacity_if_full(index_t *index){
    return;
}
void index_free(index_t *index){
    return;
}
void index_print(index_t *index){
    return;
}
permutation_t index_get(index_t *index, size_t index){
    return NULL;
}
index_t index_distance(index_t *index, size_t a, size_t b){
    return NULL;
}
void index_copy(index_t *dest, index_t *src){
    return;
}
void index_free(index_t *target){
    return;
}

size_t comp (const void * elem1, const void * elem2){
    return NULL;
}
vector_t get_sss_pivot_indices(index_t *index, double sampling_factor, double alpha){
    return NULL;
}
vector_t force_sss_pivots(index_t *index, double sampling_factor, double precision, size_t amount){
    return NULL;
}

void build(index_t *index, dataset_t *dataset, build_paramenters_t *params){
    return NULL;
}

vector_t knn(index_t *index, dataset_t *dataset, element_t target, size_t k){
    return;
}
vector_t range_query(index_t *index, dataset_t *dataset, element_t target, double range){
    return;
}

#endif