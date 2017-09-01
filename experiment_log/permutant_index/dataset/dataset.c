#ifndef dataset_C_
#define dataset_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"

dataset_t *dcreate(size_t size)
{
    //TODO, connect to global memory space.
    dataset_t *index = (dataset_t *)malloc(sizeof(dataset_t) * size * DATASET_DIM);
    return index;
}

dataset_t* dload(char *filename, size_t size){
    dataset_t *index = dcreate(size);
    FILE *ptr;
    ptr = fopen("experiment/dataset.bin","rb");  // r for read, b for binary
    fread(index,DATASET_DIM * size,sizeof(dataset_t), ptr); // read 10 bytes to our buffer
    return index;
}

dataset_t *dget(dataset_t *index, size_t offset)
{
    dataset_t *vect = (dataset_t *)malloc(DATASET_DIM * sizeof(dataset_t));
    memcpy(vect, index + (offset), DATASET_DIM * sizeof(dataset_t));
    return vect;
}

void dcpy(dataset_t *dest, dataset_t *src)
{
    memcpy(dest, src, DATASET_DIM * sizeof(dataset_t));
}

void dfree(dataset_t *target)
{
    free(target);
}

void dprint(dataset_t *target, size_t offset)
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

dataset_t ddistance(dataset_t *dataset, size_t a, size_t b)
{
    double total_value = 0;
    size_t i = 0;
    #ifdef MANHATTAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += abs(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)]);
        }
    #elif EUCLIDEAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)], 2);
        }
        total_value = sqrt(total_value);
    #elif EUCLIDEAN_SIMPLE_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(dataset[i + (a * DATASET_DIM)] - dataset[i + (b * DATASET_DIM)], 2);
        }
    #endif
    return total_value;
}


dataset_t distance(dataset_t a, dataset_t b)
{
    double total_value = 0;
    size_t i = 0;
    #ifdef MANHATTAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += abs(a[i] - b[i]);
        }
    #elif EUCLIDEAN_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(a[i] - b[i], 2);
        }
        total_value = sqrt(total_value);
    #elif EUCLIDEAN_SIMPLE_DISTANCE
        for (i = 0; i < DATASET_DIM; i++){
            total_value += pow(a[i] - b[i], 2);
        }
    #endif
    return total_value;
}

#endif