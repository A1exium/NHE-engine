//
// Created by alexium on 01.04.2022.
//
#include "Event.h"
#include "stdio.h"
#include <stdlib.h>

Event Event_new(EventType type) {
  Event event;
  event.type = type;
  return event;
}

Event Event_keyboard_new(int key) {
  Event event = {
      .type = EventKeyboard,
      .payload.keyboard_event = {
          .key = key,
      }
  };
  return event;
}

int event_keyboard_set_key(Event *event, int key) {
  if (event->type == EventKeyboard)
    event->payload.keyboard_event.key = key;
  else
    return 1;
  return 0;
}

Event Event_custom_new(int type, void *data) {
  Event event = {
      .type = EventCustom,
      .payload.custom_event = {
          .data = data,
          .custom_event_type = type,
          },
  };
  return event;
}

int event_custom_set_type(Event *event, int type) {
  if (event->type == EventCustom)
    event->payload.custom_event.custom_event_type = type;
  else
    return 1;
  return 0;
}

int event_custom_set_data(Event *event, void *data) {
  if (event->type == EventCustom)
    event->payload.custom_event.data = data;
  else
    return 1;
  return 0;
}

void *event_server_message_get_data(Event event, DataDesealizingFunction f) {
  if (event.type == EventServerMessage) {
    void *serialized_data = event.payload.server_message_event.serialized_data;
    if (f) return f(serialized_data);
    return serialized_data;
  }
  return 0;
}

Event Event_server_message_new(int custom_type) {
  Event e = {
      .type = EventServerMessage,
      .payload.server_message_event = {
          .serialized_data = 0,
          .sender_id = 0,
          .custom_event_type = custom_type,
      }
  };
  return e;
}

int event_serialize(Event event, DataSealizingFunction f, char *dest) {
  if (event.type != EventCustom)
    return 0;
  if (f) {
    int typelen = sprintf(
        dest,
        "%d;",
        event.payload.custom_event.custom_event_type);
    return typelen + f(event.payload.custom_event.data, dest + typelen);
  }
  else
    return sprintf(dest, "%d;", event.payload.custom_event.custom_event_type);
}

char *event_deserialize(char *src, Event *event) {
  if (src == 0)
    return 0;
  event->type = EventServerMessage;
  char *p = src;
  char *prev = src;
  int is_sender_readed = 0;
  int is_type_readed = 0;
  while (*p != '\0') {
    switch (*p) {
      case '<':
        prev = p + 1;
        break;
      case ';': {
        if (!is_sender_readed) {
          event->payload.server_message_event.sender_id = atoi(prev);
          is_sender_readed = 1;
        } else if (!is_type_readed) {
          event->payload.server_message_event.custom_event_type = atoi(prev);
          is_type_readed = 1;
        } else break;
        prev = p + 1;
        break;
      }
      default:
        break;
      case '>': {
        *p = 0;
//        event->payload.server_message_event.serialized_data = 0;
        event->payload.server_message_event.serialized_data = prev == p ? 0 : prev;

        return p + 1;
      }
    }
    p++;
  }
  return 0;
}

void event_free(Event event) {
  switch (event.type) {
    case EventServerMessage:
      free(event.payload.server_message_event.serialized_data);
      break;
    default:
      break;
  }
}
