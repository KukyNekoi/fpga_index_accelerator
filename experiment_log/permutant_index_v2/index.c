#include <stdio.h>
#include "constants.h"
#include "dataset/dataset.h"
#include "dataset/element.h"

int main(int args, char **argv)
{
    element_t instance_elto;
    element_init(&instance_elto, 10);
    printf("Largo? %zu", instance_elto.dim);
    // // printf("Hello World!");
    // dataset_t *dataset = NULL;
    // dataset_load(&dataset, DATASET_LOCATION, DATASET_SIZE);
    // for(int i=0; i<10; i++){
    //     dataset_print(dataset, i);
    // }
    
    // vector_t pivots = force_sss_pivots(dataset, .01, .01, 74);
    // printf("Total pivots? %ld", pivots.size);
    // permutant_t *index = NULL;
    
    // // TODO: Save pivot binary
    // permutation_create(&index, pivots.size);
    



    // dataset_free(dataset);
    
    return 1;
}

