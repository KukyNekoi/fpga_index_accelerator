#ifndef ELEMENT_C_
#define ELEMENT_C_

#include "element.h"
#include <assert.h>
#include <stdbool.h>
/*
 * This implmementation assumes that all elements are previously created as static
 * instances. While is true that there is a small performance penalty for using
 * an extra indirection level, it should not be noticeable.
 */

void element_init(element_t *element, size_t dim){
    element->dim = dim;
    element->data = malloc(sizeof(double) * dim);
    return;
}

inline bool _element_checkbounds(element_t *element, size_t index){
    return index > 0 && element->dim < index;
}

inline double element_get(element_t *element, size_t index){
    assert(_element_checkbounds(element, index)  /* element_get out of bounds */);
    return element->data[index];
}
inline void element_set(element_t *element, size_t index, double value){
    assert(_element_checkbounds(element, index) /* element_set out of bounds */);
    element->data[index] = value;
}
double element_distance(element_t *a, element_t *b, vector_distance_method_t method){
    double total_distance = 0;
    assert(a->dim == b->dim /* both elements have different sizes */);
    switch(method){
        case manhattan_distance:
            for(int i=0; i<a->dim; i++){
                total_distance += fabs(a->data[i] - b->data[i]);
            }
            break;
        case euclidean_full_distance:
            for(int i=0; i<a->dim; i++){
                total_distance += pow(a->data[i] - b->data[i], 2);
            }
            total_distance = sqrt(total_distance);
            break;
        case euclidean_simple_distance:
            for(int i=0; i<a->dim; i++){
                total_distance += pow(a->data[i] - b->data[i], 2);
            }
            break;
    }
    return total_distance;
}

void element_free(element_t *element){
    free(element->data);
    element->dim = 0;
    return;
}
#endif