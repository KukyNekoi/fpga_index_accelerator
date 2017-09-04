#ifndef DATASET_C_
#define DATASET_C_

#include "dataset.h"

void dataset_init(dataset_t *dataset, size_t size, size_t dim){
    return;
}
void dataset_append(dataset_t *dataset, element_t value){
    return;
}
void dataset_set(dataset_t *dataset, size_t index, element_t value){
    return;
}
void dataset_double_capacity_if_full(dataset_t *dataset){
    return;
}
void dataset_free(dataset_t *dataset){
    return;
}
void dataset_print(dataset_t *dataset){
    return;
}
element_t dataset_get(dataset_t *dataset, size_t index){
    element_t null;
    return null;
}
double dataset_distance(dataset_t *dataset, size_t a, size_t b, vector_distance_method_t method){
    return 0.0;
}
void dataset_copy(dataset_t *dest, dataset_t *src){
    return;
}

#endif