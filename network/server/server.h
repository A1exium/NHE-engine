//
// Created by alexium on 01.04.2022.
//

#ifndef SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_H_
#define SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_H_

#include "tools/List.h"
#include "engine.h"

extern int SERVER_STATUS;
extern int SERVER_SOCK_FD;
extern List CONNECTIONS;

void serverListen();

void serverServe();

void serverSendAll(char *data, unsigned int data_len);

void serverSendEvent(Event event, int (*f)(void *, char *));

#endif //SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_H_
