//
// Created by alexium on 01.04.2022.
//

#ifndef SGM_SRC_ENGINE_TOOLS_SIZEDARRAY_H_
#define SGM_SRC_ENGINE_TOOLS_SIZEDARRAY_H_

#include <stdlib.h>

typedef struct Array_s *Array;

Array Array_new(ssize_t length);

void Array_free(Array array);

#endif //SGM_SRC_ENGINE_TOOLS_SIZEDARRAY_H_
