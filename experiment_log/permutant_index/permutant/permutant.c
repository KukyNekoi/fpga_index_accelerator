#ifndef PERMUTANT_C_
#define PERMUTANT_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "permutant.h"

permutant_t* create_index(size_t size)
{
    //TODO, connect to global memory space.
    permutant_t *index = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE * size);
    return index;
}

permutant_t* get_permutation_from_index(permutant_t *index, size_t offset){
    permutant_t *perm = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    memcpy(perm, index+(offset*PERMUTATION_SIZE), sizeof(permutant_t)*PERMUTATION_SIZE);
    return perm;
}

permutant_t* create_permutation(){
    permutant_t *perm = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    return perm;
}

void copy_permutation(permutant_t *dest, permutant_t *src){
    memcpy(dest, src, sizeof(permutant_t)*PERMUTATION_SIZE);
}

void destroy_permutation(permutant_t *target)
{
    free(target);
}

void print_permutation(permutant_t *target, size_t offset){
    printf("(");
    for(size_t i=0; i<PERMUTATION_SIZE; i++){
        printf("%d", (int)target[i+(offset*PERMUTATION_SIZE)]);
        if(i<PERMUTATION_SIZE-1){
            printf(" ");
        }
    }
    printf(")\n");
}

// void random_permutation(permutant_t *target, size_t offset){
//     printf("(");
//     for(size_t i=0; i<PERMUTATION_SIZE; i++){
//         printf("%d", (int)target[i+offset]);
//         if(i<PERMUTATION_SIZE-1){
//             printf(" ");
//         }
//     }
//     printf(")\n");
// }

/*
 Since all permutants are numbered from 0..p-1 we can invert the index for
 most compared element in order to ease future queries.

 BEWARE THAT THIS DOESNT WORK IF THE RANGE IS NOT 0..p-1
 */
permutant_t* invert_permutation(permutant_t *target)
{
    permutant_t *inverted = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        inverted[target[i]] = i;
    }
    return inverted;
};

permutant_t* invert_permutation_on_index(permutant_t *index, size_t offset)
{
    permutant_t *inverted = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        inverted[index[i + offset]] = i;
    }
    return inverted;
};

// Both functions recieve an index, an inverted permutation and a target permutation.
permutant_distance_t spearman_rho(permutant_t *index, permutant_t *inverted_permutation)
{
    permutant_distance_t distance = 0;
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        permutant_distance_t temp = (inverted_permutation[index[i]] - i);
        distance += temp * temp;
    }
    return distance;
};

permutant_distance_t spearman_footrule(permutant_t *index, permutant_t *inverted_permutation)
{
    permutant_distance_t distance = 0;
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        distance += (abs(inverted_permutation[index[i]] - i));
    }
    return distance;
};

#endif