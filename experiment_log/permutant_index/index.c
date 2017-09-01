#include <stdio.h>
#include "constants.h"
#include "indexing/indexing.h"
#include "permutant/permutant.h"
#include "dataset/dataset.h"

int main(int args, char **argv)
{
    // printf("Hello World!");
    dataset_t *dataset = dload(DATASET_LOCATION, DATASET_DIM);
    for(int i=0; i<10; i++){
        dprint(dataset, i);
    }
    
    // // permutant_t *inverted = pgetinvert( (permutant_t*) dataset, 0);
    // pprint(inverted, 0);
    // printf("Distance: %hu\n", pspearman_footrule(dataset, 1, inverted));
    get_sss_pivots(dataset, .01,.1);
    dfree(dataset);
    return 1;
}