//
// Created by alexium on 18.03.2022.
//

#include "EventPool.h"
#include <stdlib.h>

#define EVENT_POOL_START_LENGTH 5

void EventPool_create() {
  eventPool.max_length = EVENT_POOL_START_LENGTH;
  eventPool.event_queue = malloc(sizeof(Event) * eventPool.max_length);
  eventPool.length = 0;
}

void Event_throw(Event event) {
  eventPool.event_queue[eventPool.length] = event;
  eventPool.length++;
  if (eventPool.length == eventPool.max_length) {
    eventPool.max_length += EVENT_POOL_START_LENGTH;
    eventPool.event_queue = realloc(eventPool.event_queue, eventPool.max_length);
  }
}

extern int Event_drain(Event *event_var) {
  if (eventPool.length == 0) {
    return 0;
  } else {
    *event_var = eventPool.event_queue[eventPool.length - 1];
    eventPool.length -= 1;
    return 1;
  }
}
