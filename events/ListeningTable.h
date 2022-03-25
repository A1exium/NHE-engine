//
// Created by alexium on 19.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_
#define SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_

#include "Event.h"
#include "EventCallbackArgs.h"
#include "EventCallback.h"

typedef void **HashTable;

void ListeningTable_init();

extern HashTable listeningTable;

extern void addEventListener(Event target, EventCallback, EventCallbackArgs);

void listeningTable_call(Event event);

#endif //SGM_SRC_ENGINE_EVENTS_LISTENINGTABLE_H_
