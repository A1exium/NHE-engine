//
// Created by alexium on 07.04.2022.
//

#ifndef SGM_SRC_ENGINE_NETWORK_MOD_PUB_H_
#define SGM_SRC_ENGINE_NETWORK_MOD_PUB_H_

#include "events/mod_pub.h"

extern int CLIENT_STATUS;
extern int CLIENT_ID;
extern void (*send_event)(Event, int (*)(void *, char *));

#endif //SGM_SRC_ENGINE_NETWORK_MOD_PUB_H_
