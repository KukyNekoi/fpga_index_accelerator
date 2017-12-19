#include <stdio.h>
#include "lib/dataset.h"
#include "lib/element.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define DEBUG

int generate_dataset(int dataset_size, int dimensions){
//    char str_size[12], str_dim[12];
//    sprintf(str_size, "%d", dataset_size);
//    sprintf(str_dim, "%d", dimensions);
    printf("generating dataset...\n");
    dataset_t dataset;
    dataset_init(&dataset, dataset_size, dimensions);
    for(size_t i=0; i<dataset_size; i++){
        element_t instance_elto;
        element_init(&instance_elto, dimensions);
        for(int j=0; j<dimensions; j++){
            instance_elto.data[j] = (double)rand()/(double)(RAND_MAX/1.0);
        }
        dataset_append(&dataset, instance_elto);
    }
    FILE *write_ptr;
    const char str_filename[100];
    snprintf(str_filename, sizeof str_filename, "dataset_N%d_D%d.bin", (int)log2(dataset_size), dimensions);
    write_ptr = fopen(str_filename,"wb");  // w for write, b for binary
    fwrite(dataset.data, sizeof(double) * dataset.dim * dataset.size, 1, write_ptr); // write 10 bytes from our buffer
#ifdef DEBUG
    printf("building dataset_N2e%d_D%d.bin\n", (int)log2(dataset_size), dimensions);
//    dataset_print(&dataset);
#endif
    return 0;
}

int main(int args, char **argv)
{

    srand((unsigned int)time(NULL));
    element_t instance_elto;
    element_init(&instance_elto, 10);
    printf("Largo? %zu\n", instance_elto.dim);
    for(int i=2; i<=10; i++){
        for(int j=6; j<=24;j++){
            generate_dataset(pow(2,j),pow(2,i));//100000,32);
        }
    }

    // // printf("Hello World!");
//     dataset_t *dataset = NULL;
//     dataset_load(&dataset, DATASET_LOCATION, DATASET_SIZE);
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
