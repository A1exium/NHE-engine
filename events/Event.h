//
// Created by alexium on 18.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENT_H_
#define SGM_SRC_ENGINE_EVENTS_EVENT_H_

#include "../objects/GameObject.h"

#define EVENT_TYPE_COUNT 3
#define EVENT_TYPE_KEYBOARD_COUNT 256
#define EVENT_TYPE_MOUSE_COUNT 3

typedef enum EventType_t {
  Keyboard = 0,
  Mouse = 1,
//  ObjectClick,
  LoopEvent = 2,
} EventType;

typedef struct Event_s {
  EventType type;
  int key;
  GameObject *clicked_object;
  int click_type;
} Event;



#endif //SGM_SRC_ENGINE_EVENTS_EVENT_H_
