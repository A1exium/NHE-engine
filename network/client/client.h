//
// Created by alexium on 04.04.2022.
//

#ifndef SGM_SRC_ENGINE_NETWORK_CLIENT_CLIENT_H_
#define SGM_SRC_ENGINE_NETWORK_CLIENT_CLIENT_H_

#include "events/Event.h"

extern int CLIENT_STATUS;
extern int CLIENT_ID;

extern void clientProvideEvents();

extern void sendEvent(Event event, int (*f)(void *, char *));

#endif //SGM_SRC_ENGINE_NETWORK_CLIENT_CLIENT_H_
