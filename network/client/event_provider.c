//
// Created by alexium on 31.03.2022.
//

#include "events/event_provider.h"
#include "events/Event.h"
#include <stdio.h>
#include <sys/socket.h>
#include "client.h"

extern int CLIENT_SOCK_FD;
extern char* RECV_BUFFER;

#include "string.h"

extern void clientProvideEvents() {
  RECV_BUFFER = memset(RECV_BUFFER, 0, 1024);
  while (recv(CLIENT_SOCK_FD, RECV_BUFFER, 1024, 0) > 0) {
    Event event;
    char *next = RECV_BUFFER;
    while ((next = event_deserialize(next, &event))) {
      Event_throw(event);
    }
  }
}

extern void sendEvent(Event event, DataSealizingFunction f) {
  if (CLIENT_STATUS == 1 && event.type == EventCustom) {
    static char buf[1024];
    int len;
    if ((len = event_serialize(event, f, buf)) > 0) {
      send(CLIENT_SOCK_FD, buf, len, 0);
    }
  }
}
