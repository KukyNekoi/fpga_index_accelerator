//
// Created by Erik Regla on 11/15/17.
//

#ifndef PERMUTANT_INDEX_DATASET_H
#define PERMUTANT_INDEX_DATASET_H


#include <inttypes.h>
#include "element.h"
#include <stdlib.h>
// This defines a structure for datasets
typedef struct{
    size_t size;
    size_t capacity;
    size_t dim;
    double *data;
} dataset_t;

void dataset_init(dataset_t *dataset, size_t size, size_t dim);
void dataset_append(dataset_t *dataset, element_t value);
void dataset_set(dataset_t *dataset, size_t index, element_t value);
void dataset_double_capacity_if_full(dataset_t *dataset);
void dataset_free(dataset_t *dataset);
void dataset_print(dataset_t *dataset);
element_t dataset_get(dataset_t *dataset, size_t index);
double dataset_distance(dataset_t *dataset, size_t a, size_t b, vector_distance_method_t method);
void dataset_copy(dataset_t *dest, dataset_t *src);
void dataset_free(dataset_t *target);


#endif //UNTITLED_DATASET_H
