//
// Created by alexium on 01.04.2022.
//

#ifndef SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_INIT_H_
#define SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_INIT_H_

#include "tools/List.h"

extern int SERVER_SOCK_FD;
extern List CONNECTIONS;
extern int SERVER_STATUS;

int serverInit(char *addr, unsigned int port);


#endif //SGM_SRC_ENGINE_NETWORK_SERVER_SERVER_INIT_H_
