//
// Created by alexium on 19.03.2022.
//

#include "ListeningTable.h"
#include "PackedFunction.h"
#include "Event.h"
#include <stdlib.h>

void ListeningTable_init() {
  listeningTable = calloc(sizeof(HashTable), EVENT_TYPE_COUNT);
  listeningTable[Keyboard] = calloc(sizeof(HashTable), EVENT_TYPE_KEYBOARD_COUNT);
  listeningTable[Mouse] = calloc(sizeof(HashTable), EVENT_TYPE_MOUSE_COUNT);
  listeningTable[LoopEvent] = 0;
}

void listeningTable_call(Event event) {
  PackedFunction packed = 0;
  switch (event.type) {
    case Mouse:
    case Keyboard:
      packed = ((HashTable)listeningTable[event.type])[event.key];
      break;
    case LoopEvent:
      packed = listeningTable[LoopEvent];
      break;
    default:
      break;
  }
  if (packed)
    packedFunction_call(packed);
}

PackedFunction function_pack(EventCallback f, EventCallbackArgs args) {
  PackedFunction packed = malloc(sizeof(struct PackedFunction_s));
  packed->f = f;
  packed->args = args;
  return packed;
}


extern void addEventListener(Event target, EventCallback func, EventCallbackArgs args) {
  switch (target.type) {
    case Mouse:
    case Keyboard: {
      PackedFunction current_f = ((HashTable)listeningTable[Keyboard])[target.key];
      if (current_f) free(current_f);
      ((HashTable)listeningTable[Keyboard])[target.key] = function_pack(func, args);
      break;
    }
    case LoopEvent: {
      PackedFunction current_f = listeningTable[LoopEvent];
      if (current_f) free(current_f);
        listeningTable[LoopEvent] = function_pack(func, args);
    }
    default:
      break;
  }
}
