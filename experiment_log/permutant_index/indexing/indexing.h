#ifndef INDEXING_H_
#define INDEXING_H_

#include <inttypes.h>
#include "../constants.h"
#include "../dataset/dataset.h"
#include "../vector/vector.h"

size_t comp (const void * elem1, const void * elem2);
vector_t get_sss_pivots(dataset_t *dataset, double factor, double alpha);
vector_t force_sss_pivots(dataset_t *dataset, double factor, double precision, size_t amount);

#include "indexing.c"
#endif