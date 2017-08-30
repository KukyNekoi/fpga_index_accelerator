#include <stdio.h>
#include "permutant/permutant.h"

int main(int args, char **argv){
    printf("Hello World!");
    permutation_t *target =  create_permutation(3);
    destroy_permutation(target);
    return 1;
}