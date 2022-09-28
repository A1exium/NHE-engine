//
// Created by alexium on 07.04.2022.
//
#include "client/client.h"

void (*send_event)(Event, int (*)(void *, char *)) = 0;
