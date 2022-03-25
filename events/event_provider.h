//
// Created by alexium on 23.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENT_PROVIDER_H_
#define SGM_SRC_ENGINE_EVENTS_EVENT_PROVIDER_H_

//#include "EventPool.h"
#include "ListeningTable.h"
#include "Event.h"

extern void Event_throw(Event new_event);

extern void provideEvents();

#endif //SGM_SRC_ENGINE_EVENTS_EVENT_PROVIDER_H_
