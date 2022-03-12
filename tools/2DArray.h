//
// Created by alexium on 06.03.2022.
//

#ifndef SGM_SRC_ENGINE_TOOLS_2DARRAY_H_
#define SGM_SRC_ENGINE_TOOLS_2DARRAY_H_

#include <stdlib.h>

#define Array2D_new_default(type, width, height, name, default_element) \
  type **name = (type **)malloc(sizeof(type *) * width);  \
  for (int __i = 0; __i < width; __i++) {      \
    name[__i] = (type *)malloc(sizeof(type) * height);                  \
    for (int __j = 0; __j < height; __j++) { \
      name[__i][__j] = default_element;                                        \
  } \
}

#define Array2D_new(type, width, height, name) \
  type **name = (type **)malloc(sizeof(type *) * width);  \
  for (int __i = 0; __i < width; __i++) {      \
    name[__i] = (type *)malloc(sizeof(type) * height);          \
  }
#endif //SGM_SRC_ENGINE_TOOLS_2DARRAY_H_
