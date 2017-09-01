#ifndef dataset_H_
#define dataset_H_

#include <inttypes.h>
#include "../constants.h"

#ifndef VECTOR_SIZE
#define VECTOR_SIZE 8
#endif
typedef float dataset_t;

// Moves pointer at specific offset based on VECTOR_DIM
#define VECTOR_AT(X, Y) ( X + (Y*VECTOR_SIZE) ) 

dataset_t *dcreate(size_t size);
dataset_t* dload(char *filename, size_t size);
dataset_t *dget(dataset_t *index, size_t offset);
dataset_t ddistance(dataset_t *dataset, size_t a, size_t b);
dataset_t distance(dataset_t a, dataset_t b);

void dcpy(dataset_t *dest, dataset_t *src);
void dfree(dataset_t *target);
void dprinti(dataset_t *target, size_t offset);

#include "dataset.c"
#endif