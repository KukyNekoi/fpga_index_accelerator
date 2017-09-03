#ifndef ELEMENT_H_
#define ELEMENT_H_
// Defines a common structure to work with element elements.
// Those elements acts as a wappers for element structures, delegating
typedef struct{
    size_t dim,         // Dimensions of data for memory reshaping
    double_t *data        // Data.
} element_t;

typedef enum {
    manhattan_distance,
    euclidean_full_distance,
    euclidean_simple_distance
} vector_distance_method_t;

void element_init(element_t *element, size_t dim);
inline double_t element_get(element_t *element, size_t index);
inline void element_set(element_t *element, size_t index, double_t value);
void element_free(element_t *element);
double_t element_distance(element_t *a, element_t *a, vector_distance_method_t method);

#include "element.c"
#endif