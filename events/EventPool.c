//
// Created by alexium on 18.03.2022.
//

#include "EventPool.h"
#include <stdlib.h>

#define EVENT_POOL_START_LENGTH 2

void EventPool_create() {
  eventPool.max_length = EVENT_POOL_START_LENGTH;
  eventPool.event_queue = calloc(eventPool.max_length,sizeof(struct Event_s));
  eventPool.length = 0;
}

#include <stdio.h>

void Event_throw(Event event) {
//  printf("<%d>\n", eventPool.length);
  eventPool.event_queue[eventPool.length] = event;
  eventPool.length++;
  if (eventPool.length == eventPool.max_length) {
    eventPool.max_length *= EVENT_POOL_START_LENGTH;
    eventPool.event_queue = realloc(eventPool.event_queue, eventPool.max_length * sizeof(struct Event_s));
  }
}

extern int Event_drain(Event *event_var) {
  if (eventPool.length == 0) {
    return 0;
  } else {
    eventPool.length -= 1;
    *event_var = eventPool.event_queue[eventPool.length];
    return 1;
  }
}
