//
// Created by alexium on 25.03.2022.
//

#ifndef SGM_SRC_ENGINE_EVENTS_EVENTCALLBACK_H_
#define SGM_SRC_ENGINE_EVENTS_EVENTCALLBACK_H_

#include "EventCallbackArgs.h"
#include "Event.h"

typedef void (*EventCallback)(Event, EventCallbackArgs);

#endif //SGM_SRC_ENGINE_EVENTS_EVENTCALLBACK_H_
