//
// Created by Erik Regla on 11/15/17.
//

#include "index.h"
#include <assert.h>
#include <stdio.h>

bool _index_checkbounds(index_t *index_body, size_t index){
    return  index < index_body->capacity;
}

void index_init(index_t *index, size_t size, size_t dim){
    index->size = 0;
    index->dim = dim;
    index->capacity = index->size;
    index->data = malloc(sizeof(uint16_t) * index->capacity * index->dim);
    return;
}


void index_append(index_t *index_body, permutation_t value){
    index_double_capacity_if_full(index_body);
    index_set(index_body, index_body->size, value);
    index_body->size += 1;
    return;
}

// It's not expected to use this function outside the inner index scope, as it can induce error.
// Indices should be populated though append method and set should only be used as a way to change values.
void index_set(index_t *index_body, size_t index, permutation_t value){
    assert(_index_checkbounds(index_body, index));
    assert(value.dim == index_body->dim);
    for(size_t i=0; i<index_body->dim; i++){
        index_body->data[(index*index_body->dim) + i] = permutation_get(&value, i);
    }
    return;
}

void index_double_capacity_if_full(index_t *index_body){
    if(index_body->capacity-1 == index_body->size){
        index_body->capacity += 2;
        unsigned int *result = realloc(index_body->data, sizeof(double) * index_body->dim * index_body->capacity);
        assert(result != NULL);
    }
}

void index_free(index_t *index_body){
    free(index_body->data);
    free(index_body);
    return;
}

void index_print(index_t *index_body){
    printf("index@%p\n", index_body);
    for(int i=0; i<index_body->size; i++){
        printf("\t");
        permutation_t ptr = index_get(index_body, i);
        permutation_print(&ptr);
    }
    return;
}

permutation_t index_get(index_t *index_body, size_t index){
    assert(index < index_body->size);
    permutation_t permutation;
    permutation_init(&permutation, index_body->dim);
    for(int i=0; i<permutation.dim; i++){
        permutation_set(&permutation, i, index_body->data[(index*index_body->dim) + i]);
    }
    return permutation;
}

//index_t index_distance(index_t *index_body, size_t a, size_t b){
//
//    return 0;
//}

void index_copy(index_t *dest, index_t *src){
    return;
}


//size_t comp (const void * elem1, const void * elem2){
//    return NULL;
//}
//vector_t get_sss_pivot_indices(index_t *index_body, double sampling_factor, double alpha){
//    return NULL;
//}
//vector_t force_sss_pivots(index_t *index_body, double sampling_factor, double precision, size_t amount){
//    return NULL;
//}
//
//void build(index_t *index_body, dataset_t *dataset, build_paramenters_t *params){
//    return NULL;
//}
//
//vector_t knn(index_t *index_body, dataset_t *dataset, element_t target, size_t k){
//    return;
//}
//vector_t range_query(index_t *index_body, dataset_t *dataset, element_t target, double range){
//    return;
//}
