//
// Created by alexium on 18.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENT_H_
#define SGM_SRC_ENGINE_EVENTS_EVENT_H_

typedef struct GameObject_s *GameObject;

//#include "engine.h"
#include "../geometry/Position.h"

typedef enum EventType_t {
  EventKeyboard = 0,
  EventMouse = 1,
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

typedef void *DataDesealizingFunction(char *src);
typedef int DataSealizingFunction(void *data, char *dest);

Event Event_keyboard_new(int key);

int event_keyboard_set_key(Event *event, int key);

Event Event_custom_new(int type, void *data);

int event_custom_set_type(Event *event, int type);

int event_custom_set_data(Event *event, void *data);

int event_serialize(Event event, DataSealizingFunction, char *dest);

char *event_deserialize(char *src, Event *event);

int event_custom_set_data(Event *event, void *data);

void *event_server_message_get_data(Event event, DataDesealizingFunction f);

Event Event_server_message_new(int custom_type);

void event_free(Event event);

#endif //SGM_SRC_ENGINE_EVENTS_EVENT_H_
