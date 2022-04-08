//
// Created by alexium on 01.04.2022.
//
#include "Event.h"
#include "stdio.h"

int Event_serialize(Event event, char *dest) {
  return sprintf(dest,"%d|%d|%d-",
          event.type,
          event.key,
          event.click_type
          );
}

int Event_deserialize(char *src, Event *event) {
  return sscanf(src, "%d|%d|%d-",
                &event->type,
                &event->key,
                &event->click_type
  ) != 3;
}
