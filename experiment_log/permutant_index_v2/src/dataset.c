#ifndef DATASET_C_
#define DATASET_C_

#include "./../include/dataset.h"
#include <assert.h>
#include <errno.h>

void dataset_init(dataset_t *dataset, size_t size, size_t dim){
    dataset->dim = dim;
    dataset->size = 0;
    dataset->capacity = size;
    dataset->data = malloc(sizeof(double) * dim * dataset->capacity);
    return;
}
void dataset_append(dataset_t *dataset, element_t value){
    dataset_double_capacity_if_full(dataset);
    dataset_set(dataset, dataset->size, value);
    dataset->size += 1;
    return;
}
void dataset_set(dataset_t *dataset, size_t index, element_t value){
    assert(index < dataset->size);
    for(int i=0; i<value.dim; i++){
        dataset->data[i + (index*dataset->dim)] = element_get(&value, i);
    }
    return;
}
void dataset_double_capacity_if_full(dataset_t *dataset){
    if(dataset->capacity-1 == dataset->size){
        dataset->capacity += 2;
        unsigned int *result = realloc(dataset->data, sizeof(double) * dataset->dim * dataset->capacity);
        assert(result != NULL);
    }
    return;
}
void dataset_free(dataset_t *dataset){
    free(dataset->data);
    free(dataset);
    return;
}
void dataset_print(dataset_t *dataset){
    printf("dataset@%p", dataset);
    for(int i=0; i<dataset->size; i++){
        printf("\t");
        element_t ptr = dataset_get(dataset, i);
        element_print(&ptr);
    }
    return;
}
element_t dataset_get(dataset_t *dataset, size_t index){
    assert(index < dataset->size);
    element_t element;
    element_init(&element, dataset->dim);
    for(int i=0; i<element.dim; i++){
        element_set(&element, i, dataset->data[(index*dataset->dim) + i]);
    }
    return element;
}
double dataset_distance(dataset_t *dataset, size_t a, size_t b, vector_distance_method_t method){
    return 0.0;
}
void dataset_copy(dataset_t *dest, dataset_t *src){
    return;
}

#endif