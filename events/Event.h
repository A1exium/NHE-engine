//
// Created by alexium on 18.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENT_H_
#define SGM_SRC_ENGINE_EVENTS_EVENT_H_

typedef struct GameObject_s *GameObject;

#define EVENT_TYPE_COUNT 3
#define EVENT_TYPE_KEYBOARD_COUNT 256
#define EVENT_TYPE_MOUSE_COUNT 3

//#include "engine.h"
#include "../geometry/Position.h"

typedef enum EventType_t {
  EventKeyboard = 0,
  EventMouse = 1,
//  ObjectClick,
  EventLoop = 2,
  EventServerMessage = 3,
  EventCustom = 4,
} EventType;

struct EventKeyboard_s {
  int key;
};

struct EventMouse_s {
  int key;
  Position click_pos;
};

struct EventCustom_s {
  int custom_event_type;
  void *data;
};

struct EventServerMessage_s {
  int sender_id;
  int custom_event_type;
  char *serialized_data;
};

typedef struct Event_s {
  EventType type;
  union EventSpecification_u {
    struct EventKeyboard_s keyboard_event;
    struct EventMouse_s mouse_event;
    struct EventCustom_s custom_event;
    struct EventServerMessage_s server_message_event;
  } payload;
} Event;

Event Event_new(EventType type);

Event Event_keyboard_new(int key);

int event_keyboard_set_key(Event *event, int key);

Event Event_custom_new(int type, void *data);

int event_custom_set_type(Event *event, int type);

int event_custom_set_data(Event *event, void *data);

int Event_serialize(Event event, int(*serializing_function)(void *, char *dest), char *dest);

int Event_deserialize(char *src, Event *event);

#endif //SGM_SRC_ENGINE_EVENTS_EVENT_H_
