//
// Created by Erik Regla on 11/15/17.
//

#include "permutant.h"
#include "index.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
/**
 * @brief  Initialises a permutation structure
 * @note   Should be inlined.
 * @param  *permutation: permutation structure to be initialised
 * @param  dim: dimension of the structure, a.k.a. permutation length
 * @retval None
 */
void permutation_init(permutation_t *permutation, size_t dim){
    permutation->data = malloc(sizeof(uint16_t) * dim);
    permutation->is_inverted = false;
    permutation->inverted = NULL;
    permutation->dim = dim;
    return;
}

/**
 * @brief  Sets the value of the i-th element in a certain permutation.
 * @note   Should be inlined?
 * @param  *permutation: the permutation to be altered
 * @param  index: the index of the i-th element to set, starting from 0.
 * @param  value: the value to set at the specified index
 * @retval None
 */
void permutation_set(permutation_t *permutation, size_t index, uint16_t value){
    assert(_permutation_checkbounds(permutation, index));
    permutation->data[index] = value;
    return;
}

/**
 * @brief  Retrieves a copy of the i-th element in a certain permutation.
 * @note   Should be inlined.
 * @param  *permutation: the permutation
 * @param  index: the index of the i-th to be retrieved, starting from 0.
 * @retval the i-th element in the permutation.
 */
uint16_t permutation_get(permutation_t *permutation, size_t index){
    assert(_permutation_checkbounds(permutation, index));
    return permutation->data[index];
}

/**
 * @brief  Releases a permutation from memory
 * @note
 * @param  *permutation: the permutation to be released.
 * @retval None
 */
void permutation_free(permutation_t *permutation){
    if(permutation->data != NULL) free(permutation->data);
    if(permutation->inverted != NULL) free(permutation->inverted);
    free(permutation);
    return;
}

/**
 * @brief  Prints a permutation
 * @note
 * @param  *permutation: the permutation
 * @retval None
 */
void permutation_print(permutation_t *permutation){
    printf("permutation@%p[", permutation);
    for(int i=0; i<permutation->dim; i++) {
        printf("%d", permutation->data[i]);
        if(i < permutation->dim -1){
            printf(", ");
        }
    }
    printf("]\n");
    if(permutation->is_inverted == true) {
        printf("invertedper@%p[", permutation);
        for(int i=0; i<permutation->dim; i++) {
            printf("%d", permutation->inverted[i]);
            if(i < permutation->dim -1){
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * @brief  Permutation distance between two permutation structs
 * @note   This uses spearman-rho or spearman-footrule. Generates inverted permutation as a byproduct.
 * @param  *a: first element. Target of permutant inversion.
 * @param  *b: second element.
 * @param  method: spearman_footrule or spearman_rho
 * @retval the permutation distance between a and b
 */
size_t permutation_distance(permutation_t *a, permutation_t *b, permutation_distance_methods_t method){
    _permutation_invert_if_not(a);
    assert(a->dim == b->dim);

    size_t distance = 0;
    for (size_t i = 0; i < a->dim; i++) {
        if(method == spearman_footrule){

            distance += (a->inverted[b->data[i]] > i) ? (a->inverted[b->data[i]] - i): (i - a->inverted[b->data[i]]);
        }
        else if (method == spearman_rho){
            size_t temp = (a->inverted[b->data[i]] > i) ? (a->inverted[b->data[i]] - i): (i - a->inverted[b->data[i]]);
            distance += temp * temp;
        }
        else{
            distance = 0;
        }
    }
    return distance;
}

/**
 * @brief  Copies a permutation at memory level.
 * @note   Equivalent to memcpy?
 * @param  *dest: destination pointer
 * @param  *src: source pointer
 * @retval None
 */
void permutation_copy(permutation_t *dest, permutation_t *src){
    dest->dim = src->dim;
    dest->is_inverted = src->is_inverted;
    memcpy(dest->data, src->data, sizeof(uint16_t) * src->dim);
    if(src->is_inverted == true){
        memcpy(dest->inverted, src->inverted, sizeof(uint16_t) * src->dim);
    }
    else{
        dest->inverted = NULL;
    }
    return;
}

/**
 * @brief  Checks the memory bounds for a permutation
 * @note   uses the dimension to check the bounds.
 * @param  *permutation: the permutation
 * @param  index: position to be checked
 * @retval true if the memory address is valid.
 */
inline bool _permutation_checkbounds(permutation_t *permutation, size_t index){
    return  index < permutation->dim;
}

/**
 * @brief  Inverts a permutation if is not inverted yet
 * @note   if the permutation has an inverted index already, then this is ignored.
 * @param  *permutation: the permutation
 * @retval None
 */
void _permutation_invert_if_not(permutation_t *permutation){
    permutation->inverted = malloc(sizeof(uint16_t) * permutation->dim);
    for (size_t i=0; i < permutation->dim; i++) {
        permutation->inverted[permutation->data[i]] = i;
    }
    permutation->is_inverted = true;
}