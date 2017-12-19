//
// Created by Erik Regla on 11/15/17.
//

#ifndef PERMUTANT_INDEX_ELEMENT_H
#define PERMUTANT_INDEX_ELEMENT_H

#include <stdlib.h>
#include <stdbool.h>

// Defines a common structure to work with element elements.
// Those elements acts as a wappers for element structures, delegating
typedef struct {
    size_t dim;
    double *data;
} element_t;

typedef enum {
    manhattan_distance,
    euclidean_full_distance,
    euclidean_simple_distance
} vector_distance_method_t;

void element_init(element_t *element, size_t dim);
// inline
double element_get(element_t *element, size_t index);
// inline
void element_set(element_t *element, size_t index, double value);
void element_free(element_t *element);
double element_distance(element_t *a, element_t *b, vector_distance_method_t method);
void element_print(element_t *element);
// inline
bool _element_checkbounds(element_t *element, size_t index);


#endif //PERMUTANT_INDEX_ELEMENT_H
