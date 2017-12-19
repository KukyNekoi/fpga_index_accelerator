#ifndef C_VECTOR_H_
#define C_VECTOR_H_

#include <stdlib.h>

#ifndef VECTOR_INITIAL_CAPACITY
#define VECTOR_INITIAL_CAPACITY 100
#endif

typedef size_t element_t;
// Define a vector type
typedef struct {
  size_t size;      // slots used so far
  size_t capacity;  // total available slots
  element_t *data;     // array of integers we're storing
} vector_t;

void vector_init(vector_t *vector); 
void vector_append(vector_t *vector, element_t value);
element_t vector_get(vector_t *vector, size_t index);
void vector_set(vector_t *vector, size_t index, element_t value);
void vector_double_capacity_if_full(vector_t *vector);
void vector_free(vector_t *vector);
void vector_print(vector_t *vector);

#include "vector.c"
#endif