#include <stdio.h>
#include "permutant/permutant.h"

int main(int args, char **argv)
{
    // printf("Hello World!");
    permutant_t *index = create_index(2);
    index[0] = 1;
    index[1] = 2;
    index[2] = 4;
    index[3] = 3;
    index[4] = 1;
    index[5] = 2;
    index[6] = 3;
    index[7] = 4;
    print_permutation(index, 0);
    print_permutation(index, 1);

    permutant_t *target = get_permutation_from_index(index, 0);
    permutant_t *inverted = invert_permutation(target);
    print_permutation(inverted, 0);
    printf("Distance: %hu\n", spearman_footrule(INDEX_AT(index,1), inverted));

    
    
    destroy_permutation(index);
    return 1;
}