#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"

#include "dataset/dataset.h"

int main(int args, char **argv)
{
    int seed = time(NULL);
    srand(seed);

    FILE *write_ptr;
    system("mkdir -p experiment");
    write_ptr = fopen("experiment/dataset.bin", "wb"); // w for write, b for binary
    dataset_t *dataset = NULL;
    dataset_create(&dataset, DATASET_SIZE);
    dataset_t value = 0;
    int i = 0, j = 0;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        for (j = 0; j < DATASET_DIM; j++)
        {
            value = (dataset_t)rand() / (dataset_t)(RAND_MAX);
            // printf("value[%d](%d,%d) is %f\n", (i*DATASET_SIZE)+j,i,j, value);
            dataset[(i * DATASET_DIM) + j] = value;
            // for (int k = 0; k < DATASET_DIM; k++)
            // {
            //     print_vector_from_index(dataset, k);
            // }
            // printf("\n\n");
        }
    }
    for (i = 0; i < DATASET_SIZE; i++)
    {
        dataset_print(dataset, i);
    }
    fwrite(dataset, sizeof(dataset_t), sizeof(dataset_t) * DATASET_DIM * DATASET_SIZE, write_ptr); // write 10 bytes from our buffer
}