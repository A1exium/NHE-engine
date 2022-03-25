//
// Created by alexium on 25.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_PACKEDFUNCTION_H_
#define SGM_SRC_ENGINE_EVENTS_PACKEDFUNCTION_H_

#include "EventCallbackArgs.h"
#include "EventCallback.h"

typedef struct PackedFunction_s {
  EventCallback f;
  EventCallbackArgs args;
} *PackedFunction;

void packedFunction_call(PackedFunction pf);

#endif //SGM_SRC_ENGINE_EVENTS_PACKEDFUNCTION_H_
