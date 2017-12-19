#ifndef DATASET_H_
#define DATASET_H_

#include <inttypes.h>
#include "../constants.h"

#ifndef VECTOR_SIZE
#define VECTOR_SIZE 8
#endif
typedef float dataset_t;

// Moves pointer at specific offset based on VECTOR_DIM
#define VECTOR_AT(X, Y) ( X + (Y*VECTOR_SIZE) ) 

void dataset_create(dataset_t **index, size_t size);
void dataset_load(dataset_t **index, char *filename, size_t size);
dataset_t* dataset_get(dataset_t *index, size_t offset);
dataset_t dataset_distance(dataset_t *dataset, size_t a, size_t b);
dataset_t distance(dataset_t a, dataset_t b);

void dataset_cpy(dataset_t *dest, dataset_t *src);
void dataset_free(dataset_t *target);
void dataset_printi(dataset_t *target, size_t offset);

#include "dataset.c"
#endif