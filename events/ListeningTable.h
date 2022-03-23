//
// Created by alexium on 19.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_
#define SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_

#include "Event.h"

#define LT_KEY_MAX

typedef void **HashTable;
typedef struct EventCallbackArgs_s {
  void **storage;
  int length;
} EventCallbackArgs;
typedef void (*EventCallback)(EventCallbackArgs);

typedef struct PackedFunction_s {
  EventCallback f;
  EventCallbackArgs args;
} *PackedFunction;

extern HashTable listeningTable;

extern void ListeningTable_init();

extern void addEventListener(Event target, EventCallback, EventCallbackArgs);

extern EventCallbackArgs EventCallbackArgs_pack(int argc, void *arg,...);

void listeningTable_call(Event event);

extern void EventCallbackArgs_unpack(EventCallbackArgs _args, ...);

#endif //SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_
