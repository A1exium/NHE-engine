//
// Created by alexium on 18.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENT_H_
#define SGM_SRC_ENGINE_EVENTS_EVENT_H_

typedef struct GameObject_s *GameObject;

#define EVENT_TYPE_COUNT 3
#define EVENT_TYPE_KEYBOARD_COUNT 256
#define EVENT_TYPE_MOUSE_COUNT 3

typedef enum EventType_t {
  Keyboard = 0,
  Mouse = 1,
//  ObjectClick,
  LoopEvent = 2,
  Message = 3,
} EventType;

typedef struct Event_s {
  EventType type;
  int key;
  int click_type;
} Event;

int Event_serialize(Event event, char *dest);

int Event_deserialize(char *src, Event *event);

#endif //SGM_SRC_ENGINE_EVENTS_EVENT_H_
