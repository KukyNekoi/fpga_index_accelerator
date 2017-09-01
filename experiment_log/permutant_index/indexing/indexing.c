#ifndef INDEXING_C_
#define INDEXING_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "indexing.h"
#include "../dataset/dataset.h"
#include "../permutant/permutant.h"

size_t comp (const void * elem1, const void * elem2) {
    size_t f = *((size_t*)elem1);
    size_t s = *((size_t*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

permutant_t* get_sss_pivots(dataset_t *dataset, double factor, double alpha){
    // Random sampling to determine max distance. Otherwise, this could take an eternity TwT

    //Random seed generation for random pivot selection
    size_t random_number = 0;
    FILE *random_source;
    random_source = fopen("/dev/urandom", "r");
    fread(&random_number, 1, sizeof(size_t), random_source);

    size_t current_index_size = DATASET_SIZE;
    size_t sss_sample_size;

    if(factor == 0.0)
        sss_sample_size = cbrt(current_index_size);
    else
        sss_sample_size = factor * (current_index_size);

    size_t *sample = (size_t *) malloc(sizeof(size_t) * sss_sample_size);
    bool uniform = true;
    // Assuming that random values are distributed evenly
    for (int i=0; i < sss_sample_size; i++){
        fread(&random_number, 1, sizeof(size_t), random_source);
        sample[i] = random_number % DATASET_SIZE;
        // printf("Random sample[%ld]: %ld\n", i ,sample[i]);
    }
    fclose(random_source);
    return NULL;    

    // Now selecting pivots
    // calculate max distance between the samples (exaustive for now)
    double max_distance = 0;
    for(int i = 0; i < sss_sample_size; i++){
        for(int j = i+1; j < sss_sample_size - 1; j++){
            double dist = ddistance(dataset, i, j);
            if(dist > max_distance)
                max_distance = dist;
        }
    }
    // printf("Max distance: %f\n", max_distance);

    // Believe it or not, we only did that to get the max distance. wwwww
    free(sample);

    
}

#endif