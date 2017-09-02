#include <stdio.h>
#include "constants.h"
#include "indexing/indexing.h"
#include "permutant/permutant.h"
#include "dataset/dataset.h"

int main(int args, char **argv)
{
    // printf("Hello World!");
    dataset_t *dataset = NULL;
    dataset_load(&dataset, DATASET_LOCATION, DATASET_SIZE);
    for(int i=0; i<10; i++){
        dataset_print(dataset, i);
    }
    
    vector_t pivots = force_sss_pivots(dataset, .01, .01, 74);
    printf("Total pivots? %ld", pivots.size);
    dataset_free(dataset);
    
    return 1;
}

