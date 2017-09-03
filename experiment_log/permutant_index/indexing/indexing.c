#ifndef INDEXING_C_
#define INDEXING_C_

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../constants.h"
#include "indexing.h"
#include "../dataset/dataset.h"
#include "../permutant/permutant.h"
#include "../vector/vector.h"

size_t comp (const void * elem1, const void * elem2) {
    size_t f = *((size_t*)elem1);
    size_t s = *((size_t*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

vector_t get_sss_pivots(dataset_t *dataset, double factor, double alpha){
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
        // printf("Random sample[%d]: %zu\n", i ,sample[i]);
    }
    fclose(random_source);
    // return NULL;    

    // Now selecting pivots
    // calculate max distance between the samples (exhaustive for now)
    double max_distance = 0;
    for(int i = 0; i < sss_sample_size; i++){
        for(int j = i+1; j < sss_sample_size - 1; j++){
            double dist = dataset_distance(dataset, i, j);
            if(dist > max_distance)
                max_distance = dist;
        }
    }
    // printf("Max distance: %f\n", max_distance);

    // Believe it or not, we only did that to get the max distance. wwwww
    free(sample);

    vector_t pivots;
    vector_init(&pivots);
    vector_append(&pivots, 0);
    
    // for each new element if distance to all pivots exceeds (max*alpha) add as pivots
    #ifndef SKIP_SSS_INTERVAL
    for(size_t i = 0; i < current_index_size; i++){
    #else
    for(size_t i = 0; i < current_index_size; i+= SKIP_SSS_INTERVAL){
    #endif
        bool accepted = true;

        for(size_t j = 0; j < pivots.size; j++){
            // vector_print(&pivots);
            double dist = dataset_distance(dataset, vector_get(&pivots, j), i);
            size_t next = vector_get(&pivots, j);
            dataset_t *a = dataset_get(dataset, next);
            dataset_t *b = dataset_get(dataset, i);

            if(dist < alpha * max_distance){
                accepted = false;
                break;
            }
        }
        if(accepted == true){
            vector_append(&pivots, i);
        }
    }
    vector_print(&pivots);
    return pivots;
}

vector_t force_sss_pivots(dataset_t *dataset, double factor, double precision, size_t amount){
    size_t lower_bound = amount * (1.0-precision);
    size_t upper_bound = amount * (1.0+precision);
    double upper_alpha_bound = 1;
    double lower_alpha_bound = 0;
    while(1){
        double curr_alpha = ((2*upper_alpha_bound)+lower_alpha_bound)/3.0;
        vector_t pivots = get_sss_pivots(dataset, factor, curr_alpha);
        if(pivots.size > upper_bound){
            lower_alpha_bound = curr_alpha;
        }
        else if(pivots.size < lower_bound){
            upper_alpha_bound = curr_alpha;
        }
        else{
            return pivots;
        }
    }
}

permutant_t* get_permutation_mapping(dataset_t *dataset, vector_t pivots, size_t offset){
    permutant_t *permutation = NULL;
    permutation_create(permutation, DATASET_SIZE);
}
#endif