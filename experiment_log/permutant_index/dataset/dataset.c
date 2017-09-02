#ifndef DATASET_C_
#define DATASET_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../constants.h"
#include "dataset.h"

void dataset_create(dataset_t **index, size_t size){
    //TODO, connect to global memory space.
    dataset_t *memory = (dataset_t *)malloc(sizeof(dataset_t) * size * DATASET_DIM);
    printf("Total size: %ld", sizeof(dataset_t) * size * DATASET_DIM);
    *index = (dataset_t *)memory;
}

void dataset_load(dataset_t **index, char *filename, size_t size){
    dataset_t *memory = NULL;
    dataset_create(&memory, size);
    FILE *ptr;
    ptr = fopen("experiment/dataset.bin","rb");  // r for read, b for binary
    fread(memory,sizeof(dataset_t),DATASET_DIM * size, ptr); // read 10 bytes to our buffer
    *index = (dataset_t *)memory;
}

dataset_t* dataset_get(dataset_t *index, size_t offset)
{
    dataset_t *vect = (dataset_t *)malloc(DATASET_DIM * sizeof(dataset_t));
    memcpy(vect, index + (offset), DATASET_DIM * sizeof(dataset_t));
    return vect;
}

void dataset_copy(dataset_t **dest, dataset_t **src)
{
    memcpy(dest, src, DATASET_DIM * sizeof(dataset_t));
}

void dataset_free(dataset_t *target)
{
    free(target);
}

void dataset_print(dataset_t *target, size_t offset)
{
    printf("(");
    for (size_t i = 0; i < DATASET_DIM; i++)
    {
        printf("%f", (dataset_t)target[i + (offset * DATASET_DIM)]);
        if (i < DATASET_DIM - 1)
        {
            printf(" ");
        }
    }
    printf(")\n");
}

dataset_t dataset_distance(dataset_t *dataset, size_t a, size_t b)
{
    double total_value = 0;
    size_t i = 0;
    #ifdef MANHATTAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += abs(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)]);
        }
    #endif
    #ifdef EUCLIDEAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)], 2);
        }
        total_value = sqrt(total_value);
    #endif
    #ifdef EUCLIDEAN_SIMPLE_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)], 2);
        }
    #endif
    return total_value;
}


dataset_t get_distance(dataset_t *a, dataset_t *b)
{
    double total_value = 0;
    size_t i = 0;
    #ifdef MANHATTAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += abs(a[i] - b[i]);
        }
    #endif
    #ifdef EUCLIDEAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(a[i] - b[i], 2);
        }
        total_value = sqrt(total_value);
    #endif
    #ifdef EUCLIDEAN_SIMPLE_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(a[i] - b[i], 2);
        }
    #endif
    return total_value;
}
#endif