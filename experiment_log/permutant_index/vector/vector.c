#ifndef VECTOR_C_
#define VECTOR_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

vector_t* create_vector(size_t size)
{
    //TODO, connect to global memory space.
    vector_t *index = (vector_t *)malloc(sizeof(vector_t) * size * VECTOR_SIZE);
    return index;
}

vector_t* copy_from_vector(vector_t *index, size_t offset){
    vector_t *vect = (vector_t *)malloc(VECTOR_SIZE * sizeof(vector_t));
    memcpy(vect, index+(offset), VECTOR_SIZE * sizeof(vector_t));
    return vect;
}

void copy_vector(vector_t *dest, vector_t *src){
    memcpy(dest, src, VECTOR_SIZE * sizeof(vector_t));
}

void destroy_vector(vector_t *target)
{
    free(target);
}

void print_vector_from_index(vector_t *target, size_t offset){
    printf("(");
    for(size_t i=0; i<VECTOR_SIZE; i++){
        printf("%f", (vector_t)target[i+(offset*VECTOR_SIZE)]);
        if(i<VECTOR_SIZE-1){
            printf(" ");
        }
    }
    printf(")\n");
}



#endif