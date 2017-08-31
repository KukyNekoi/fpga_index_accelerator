#include <stdio.h>
#include <stdlib.h>
#include "vector/vector.h"

#ifndef DATASET_SIZE
#define DATASET_SIZE 100000
#endif

int main(int args, char **argv)
{
    int seed = time(NULL);
    srand(seed);

    FILE *write_ptr;
    system("mkdir -p experiment");
    write_ptr = fopen("experiment/dataset.bin", "wb"); // w for write, b for binary
    vector_t *dataset = create_vector(DATASET_SIZE);
    vector_t value = 0;
    int i = 0, j = 0;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        for (j = 0; j < VECTOR_SIZE; j++)
        {
            value = (vector_t)rand() / (vector_t)(RAND_MAX);
            // printf("value[%d](%d,%d) is %f\n", (i*VECTOR_SIZE)+j,i,j, value);
            dataset[(i * VECTOR_SIZE) + j] = value;
            // for (int k = 0; k < DATASET_SIZE; k++)
            // {
            //     print_vector_from_index(dataset, k);
            // }
            // printf("\n\n");
        }
    }
    for (i = 0; i < DATASET_SIZE; i++)
    {
        print_vector_from_index(dataset, i);
    }
    fwrite(dataset, sizeof(vector_t), sizeof(vector_t) * DATASET_SIZE * VECTOR_SIZE, write_ptr); // write 10 bytes from our buffer
}