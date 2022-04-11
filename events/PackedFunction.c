//
// Created by alexium on 25.03.2022.
//

#include "PackedFunction.h"

void packedFunction_call(Event call_event, PackedFunction pf) {
  pf->f(call_event, pf->args);
}

