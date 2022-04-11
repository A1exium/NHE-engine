//
// Created by alexium on 01.04.2022.
//
#include "Event.h"
#include "stdio.h"

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

int Event_serialize(Event event, int(*serializing_function)(void *, char *dest), char *dest) {
  if (event.type != EventCustom)
    return 0;

  if (serializing_function)
    return sprintf(
        dest,
        "%d|",
        event.payload.custom_event.custom_event_type) +
        serializing_function(event.payload.custom_event.data, dest);
  else
    return sprintf(dest, "%d-", event.payload.custom_event.custom_event_type);
}

int Event_deserialize(char *src, Event *event) {
  event->type = EventServerMessage;
  struct EventServerMessage_s msg;
  return sscanf(
      src,
      "%d|%d|%s-",
      &event->payload.server_message_event.sender_id,
      &event->payload.server_message_event.custom_event_type,
      event->payload.server_message_event.serialized_data
      ) <= 2;
}

//int Event_serialize(Event event, char *dest) {
//  return sprintf(dest,"%d|%d|%d-",
//          event.type,
//          event.key,
//          event.click_type
//          );
//}

//int Event_deserialize(char *src, Event *event) {
//  return sscanf(src, "%d|%d|%d-",
//                &event->type,
//                &event->key,
//                &event->click_type
//  ) != 3;
//}
