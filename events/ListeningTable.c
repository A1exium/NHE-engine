//
// Created by alexium on 19.03.2022.
//

#include "ListeningTable.h"
#include "PackedFunction.h"
#include "Event.h"
#include <stdlib.h>

void ListeningTable_init() {
  listeningTable = calloc(sizeof(HashTable), EVENT_TYPE_COUNT);
  listeningTable[EventKeyboard] = calloc(sizeof(HashTable), EVENT_TYPE_KEYBOARD_COUNT);
  listeningTable[EventMouse] = calloc(sizeof(HashTable), EVENT_TYPE_MOUSE_COUNT);
  listeningTable[EventLoop] = 0;
}

void listeningTable_call(Event event) {
  PackedFunction packed = 0;
  switch (event.type) {
    case EventMouse:
    case EventKeyboard:
      packed = ((HashTable)listeningTable[event.type])[event.payload.keyboard_event.key];
      break;
    case EventLoop:
      packed = listeningTable[EventLoop];
      break;
    default:
      break;
  }
  if (packed)
    packedFunction_call(event, packed);
}

PackedFunction function_pack(EventCallback f, EventCallbackArgs args) {
  PackedFunction packed = malloc(sizeof(struct PackedFunction_s));
  packed->f = f;
  packed->args = args;
  return packed;
}


extern void addEventListener(Event target, EventCallback func, EventCallbackArgs args) {
  switch (target.type) {
    case EventMouse:
    case EventKeyboard: {
      PackedFunction current_f = ((HashTable)listeningTable[EventKeyboard])[target.payload.keyboard_event.key];
      if (current_f) free(current_f);
      ((HashTable)listeningTable[EventKeyboard])[target.payload.keyboard_event.key] = function_pack(func, args);
      break;
    }
    case EventLoop: {
      PackedFunction current_f = listeningTable[EventLoop];
      if (current_f) free(current_f);
        listeningTable[EventLoop] = function_pack(func, args);
    }
    default:
      break;
  }
}
