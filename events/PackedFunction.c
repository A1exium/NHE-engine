//
// Created by alexium on 25.03.2022.
//

#include "PackedFunction.h"

void packedFunction_call(PackedFunction pf) {
  pf->f(pf->args);
}

