#ifndef DATASET_C_
#define DATASET_C_

#include "./../include/dataset.h"
#include <assert.h>
#include <errno.h>


/** 
 * @brief  Initialises a dataset
 * @note   A dataset is a collection of n-dimensional vectors.
 * @param  *dataset: dataset to initialise
 * @param  size: amount of vectors to store on this dataset
 * @param  dim: dimension of each vector.
 * @retval None
 */
void dataset_init(dataset_t *dataset, size_t size, size_t dim){
    dataset->dim = dim;
    dataset->size = 0;
    dataset->capacity = size;
    dataset->data = malloc(sizeof(double) * dim * dataset->capacity);
    return;
}

/** 
 * @brief  Appends a vector to a dataset. If memory allocated is not enough, then it expands.
 * @note   The memory allocated doubles if not sufficient space is available
 * @param  *dataset: the dataset to add the new element
 * @param  value: a pass-by-copy parameter of the vector to add
 * @retval None
 */
void dataset_append(dataset_t *dataset, element_t value){
    dataset_double_capacity_if_full(dataset);
    dataset_set(dataset, dataset->size, value);
    dataset->size += 1;
    return;
}

/** 
 * @brief  Replaces the i-th vector of a dataset.
 * @note   
 * @param  *dataset: the dataset
 * @param  index: the i-th position to replace with value, starting from 0
 * @param  value: the element which will replace the i-th element
 * @retval None
 */
void dataset_set(dataset_t *dataset, size_t index, element_t value){
    assert(index < dataset->size);
    for(int i=0; i<value.dim; i++){
        dataset->data[i + (index*dataset->dim)] = element_get(&value, i);
    }
    return;
}

/** 
 * @brief  Doubles a dataset capacity if it hits it's maximum capacity
 * @note   If not, does nothing.
 * @param  *dataset: the dataset
 * @retval None
 */
void dataset_double_capacity_if_full(dataset_t *dataset){
    if(dataset->capacity-1 == dataset->size){
        dataset->capacity += 2;
        unsigned int *result = realloc(dataset->data, sizeof(double) * dataset->dim * dataset->capacity);
        assert(result != NULL);
    }
    return;
}

/** 
 * @brief  Frees the memory allocated for a dataset.
 * @note   This will not delete their extracted members by "pass-by-copy"
 * @param  *dataset: the dataset
 * @retval None
 */
void dataset_free(dataset_t *dataset){
    free(dataset->data);
    free(dataset);
    return;
}

/** 
 * @brief  
 * @note   
 * @param  *dataset: 
 * @retval None
 */
void dataset_print(dataset_t *dataset){
    printf("dataset@%p\n", dataset);
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
    element_t _a = dataset_get(dataset, a);
    element_t _b = dataset_get(dataset, b);
    double total_value = 0;
    switch(method){
        case manhattan_distance:
            for (size_t i = 0; i < dataset->dim; i++){
                total_value += abs(element_get(&_a, i) - element_get(&_b, i));
            }
        break;

        case euclidean_full_distance:
            for (size_t i = 0; i < dataset->dim; i++){
                total_value += pow(element_get(&_a, i) - element_get(&_b, i), 2);
            }
            total_value = sqrt(total_value);
        break;

        case euclidean_simple_distance:
            for (size_t i = 0; i < dataset->dim; i++){
                total_value += pow(element_get(&_a, i) - element_get(&_b, i), 2);
            }
        break;
    }

    return total_value;
}

void dataset_copy(dataset_t *dest, dataset_t *src){
    dest->dim = src->dim;
    dest->size = src->size;
    dest->capacity = src->size;
    dest->data = malloc(sizeof(double) * dest->dim * dest->capacity);
    memcpy(dest->data, src->data, sizeof(double) * dest->dim * dest->capacity);
    return;
}

#endif