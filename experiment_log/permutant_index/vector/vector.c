#ifndef C_VECTOR_C_
#define C_VECTOR_C_

// vector.c

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(vector_t *vector) {
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;

  // allocate memory for vector->data
  vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_append(vector_t *vector, int value) {
  // make sure there's room to expand into
  vector_double_capacity_if_full(vector);

  // append the value and increment vector->size
  vector->data[vector->size++] = value;
}

int vector_get(vector_t *vector, int index) {
  if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

void vector_set(vector_t *vector, int index, int value) {
  // zero fill the vector up to the desired index
  while (index >= vector->size) {
    vector_append(vector, 0);
  }

  // set the value at the desired index
  vector->data[index] = value;
}

void vector_double_capacity_if_full(vector_t *vector) {
  if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  }
}

void vector_free(vector_t *vector) {
  free(vector->data);
}

#endif



// // vector-usage.c

// #include <stdio.h>
// #include "vector.h"

// int main() {
//   // declare and initialize a new vector
//   Vector vector;
//   vector_init(&vector);

//   // fill it up with 150 arbitrary values
//   // this should expand capacity up to 200
//   int i;
//   for (i = 200; i > -50; i--) {
//     vector_append(&vector, i);
//   }

//   // set a value at an arbitrary index
//   // this will expand and zero-fill the vector to fit
//   vector_set(&vector, 4452, 21312984);

//   // print out an arbitrary value in the vector
//   printf("Heres the value at 27: %d\n", vector_get(&vector, 27));

//   // we're all done playing with our vector, 
//   // so free its underlying data array
//   vector_free(&vector);
// }
