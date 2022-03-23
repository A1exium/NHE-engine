//
// Created by alexium on 19.03.2022.
//

#include "ListeningTable.h"
#include "Event.h"
#include <stdlib.h>
#include <stdarg.h>

void ListeningTable_init() {
  listeningTable = calloc(sizeof(HashTable), EVENT_TYPE_COUNT);
  listeningTable[Keyboard] = calloc(sizeof(HashTable), EVENT_TYPE_KEYBOARD_COUNT);
  listeningTable[Mouse] = calloc(sizeof(HashTable), EVENT_TYPE_MOUSE_COUNT);
  listeningTable[LoopEvent] = 0;
}

void packedFunction_call(PackedFunction pf) {
  // TODO: Unpack args:
  pf->f(0);
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
  PackedFunction packed = malloc(sizeof(PackedFunction));
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

extern EventCallbackArgs EventCallbackArgs_pack(int argc, void *arg,...) {
  va_list _args;
  EventCallbackArgs args;
  args.length = argc;
  if (argc > 0) {
    args.storage = calloc(argc, sizeof(void *));
    va_start(_args, arg);
    for (int i = 0; i < argc; i++) {
      args.storage[i] = va_arg(_args, void *);
    }
    va_end(_args);
  } else
    args.storage = 0;
  return args;
}
