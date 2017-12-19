//
// Created by Erik Regla on 11/15/17.
//

#include "element.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * This implmementation assumes that all elements are previously created as static
 * instances. While is true that there is a small performance penalty for using
 * an extra indirection level, it should not be noticeable.
 */
/**
 * @brief  Initialises an element
 * @note   An element is a n-dimensional vector.
 * @param  *element: memory pointer to the vector to be initialised.
 * @param  dim: the n-dimensions
 * @retval None
 */
void element_init(element_t *element, size_t dim){
    element->dim = dim;
    element->data = malloc(sizeof(double) * dim);
    return;
}


/**
 * @brief  Checks the memory bounds for a element
 * @note   uses the dimension to check the bounds.
 * @param  *element: the element
 * @param  index: position to be checked
 * @retval true if the memory address is valid.
 */
inline bool _element_checkbounds(element_t *element, size_t index){
    return index < element->dim;
}

/**
 * @brief  Gets the i-th element (of the dataset) of a vector.
 * @note   Should be inlined
 * @param  *element: the vector to query
 * @param  index: the i-th position, starting from 0
 * @retval a copy the i-th position value
 */
double element_get(element_t *element, size_t index){
    assert(_element_checkbounds(element, index)  /* element_get out of bounds */);
    return element->data[index];
}

/**
 * @brief  Sets the i-th element of a vector.
 * @note   Should be inlined
 * @param  *element: The vector to be altered
 * @param  index: the i-th position of the element to alter, starting from 0
 * @param  value: the value to set
 * @retval None
 */
void element_set(element_t *element, size_t index, double value){
    assert(_element_checkbounds(element, index) /* element_set out of bounds */);
    element->data[index] = value;
}

/**
 * @brief  Gets the real distance between two elements (vectors)
 * @note
 * @param  *a: element 1
 * @param  *b: element 2
 * @param  method: manhattan_distance, euclidean_full_distance, euclidean_simple_distance
 * @retval the real distance between two vectors
 */
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

/**
 * @brief  Releases a vector from memory
 * @note
 * @param  *element: the vector to delete.
 * @retval None
 */
void element_free(element_t *element){
    free(element->data);
    element->dim = 0;
    element->data = NULL;
    return;
}

/**
Prints an element with a new line
*/
void element_print(element_t *element){
    printf("element@%p[", element);
    for(int i=0; i<element->dim; i++){
        printf("%f", element->data[i]);
        if(i < element->dim -1){
            printf(", ");
        }
    }
    printf("]\n");
}