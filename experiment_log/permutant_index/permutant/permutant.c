#ifndef PERMUTANT_C_
#define PERMUTANT_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "permutant.h"

void permutation_create(permutant_t **index, size_t size)
{
    //TODO, connect to global memory space.
    permutant_t *memory = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE * size);
    *index = (permutant_t *)memory;
}

void permutation_load(permutant_t **index, char *filename, size_t size){
    permutation_create(index, size);
    FILE *ptr;
    ptr = fopen("experiment/index.bin","rb");  // r for read, b for binary
    fread(index,PERMUTATION_SIZE * size, sizeof(permutant_t), ptr); // read 10 bytes to our buffer
}

permutant_t* permutation_get(permutant_t *index, size_t offset){
    permutant_t *perm = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    memcpy(perm, index+(offset*PERMUTATION_SIZE), sizeof(permutant_t)*PERMUTATION_SIZE);
    return perm;
}

void permutant_create_single(permutant_t* perm){
    perm = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
}

void permutant_copy(permutant_t *dest, permutant_t *src){
    memcpy(dest, src, sizeof(permutant_t)*PERMUTATION_SIZE);
}

void pfree(permutant_t *target)
{
    free(target);
}

void pprint(permutant_t *target, size_t offset){
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
permutant_t* get_invert_permutation(permutant_t *target)
{
    permutant_t *inverted = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        inverted[target[i]] = i;
    }
    return inverted;
};

permutant_t* permutation_get_inverted(permutant_t *index, size_t offset)
{
    permutant_t *inverted = (permutant_t *)malloc(sizeof(permutant_t) * PERMUTATION_SIZE);
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        inverted[index[i + offset]] = i;
    }
    return inverted;
};

// Both functions recieve an index, an inverted permutation and a target permutation.
permutant_distance_t permutation_spearman_rho(permutant_t *index, size_t offset,  permutant_t *inverted_permutation)
{
    permutant_t *idx = INDEX_AT(index,offset);
    permutant_distance_t distance = 0;
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        permutant_distance_t temp = (inverted_permutation[idx[i]] - i);
        distance += temp * temp;
    }
    return distance;
};

permutant_distance_t permutation_spearman_footrule(permutant_t *index, size_t offset, permutant_t *inverted_permutation)
{
    permutant_t *idx = INDEX_AT(index,offset);
    permutant_distance_t distance = 0;
    for (permutant_t i = 0; i < PERMUTATION_SIZE; i++)
    {
        distance += (abs(inverted_permutation[idx[i]] - i));
    }
    return distance;
};

#endif