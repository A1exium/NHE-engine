//
// Created by alexium on 18.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENTPOOL_H_
#define SGM_SRC_ENGINE_EVENTS_EVENTPOOL_H_

#include "List.h"
#include "Event.h"

typedef struct EventPool_s {
  int length;
  int max_length;
  Event *event_queue;
} EventPool;

extern EventPool eventPool;

extern void Event_throw(Event new_event);

int Event_drain(Event *event_var);

#endif //SGM_SRC_ENGINE_EVENTS_EVENTPOOL_H_
