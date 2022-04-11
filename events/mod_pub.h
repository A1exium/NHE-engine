//
// Created by alexium on 25.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_MOD_PUB_H_
#define SGM_SRC_ENGINE_EVENTS_MOD_PUB_H_

#include "Event.h"
#include "EventCallbackArgs.h"
#include "EventCallback.h"

extern void addEventListener(Event target, EventCallback, EventCallbackArgs);
extern void Event_throw(Event new_event);

#endif //SGM_SRC_ENGINE_EVENTS_MOD_PUB_H_
