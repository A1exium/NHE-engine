//
// Created by alexium on 01.04.2022.
//

#include "SizedArray.h"

struct Array_s {
  void *array;
  ssize_t length;
};

Array Array_new(ssize_t length) {
  Array array = malloc(sizeof(struct Array_s));
  array->length = length;
  array->array = calloc(length, sizeof(void *));
  return array;
}

void Array_free(Array array) {
  free(array->array);
  free(array);
}
