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
  vector->data = malloc(sizeof(element_t) * vector->capacity);
}

void vector_append(vector_t *vector, element_t value) {
  // make sure there's room to expand into
  vector_double_capacity_if_full(vector);

  // append the value and increment vector->size
  vector->data[vector->size++] = value;
}

element_t vector_get(vector_t *vector, size_t index) {
  if (index >= vector->size) {
    printf("Index %zd out of bounds for vector of size %zd\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

void vector_set(vector_t *vector, size_t index, element_t value) {
  // zero fill the vector up to the desired index
  while (index >= vector->size) {
    vector_append(vector, 0);
  }

  // set the value at the desired index
  vector->data[index] = value;
}

void vector_double_capacity_if_full(vector_t *vector) {
  if (vector->size >= vector->capacity) {
    // printf("ALLOCATING MEMORY!");
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    element_t *ptr = realloc(vector->data, sizeof(element_t) * vector->capacity);
    if(ptr == NULL){
      // printf("Memory allocation failed. \n"); exit(1);
    }
    else{
      vector->data = ptr;
    }
  }
}

void vector_free(vector_t *vector) {
  free(vector->data);
  vector->size = 0;
}

void vector_print(vector_t *vector) {
  printf("{");
  for(int i=0; i<vector->size; i++){
    printf("%zd", vector->data[i]);
    if(i < vector->size - 1){
      printf(" ");
    }
  }
  printf("}\n");
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
