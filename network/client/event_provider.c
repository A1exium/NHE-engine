//
// Created by alexium on 31.03.2022.
//

#include "events/event_provider.h"
#include "events/Event.h"
#include <stdio.h>
#include <sys/socket.h>
#include "client.h"

extern int CLIENT_SOCK_FD;

extern void clientProvideEvents() {
  static char buf[1024];
  while (recv(CLIENT_SOCK_FD, buf, 1024, 0) > 0) {
    Event event;
    Event_deserialize(buf, &event);
    Event_throw(event);
  }
}

extern void sendEvent(Event event, int (*f)(void *, char *)) {
  if (CLIENT_STATUS == 1) {
    static char buf[1024];
    int len = Event_serialize(event, f, buf);
    send(CLIENT_SOCK_FD, buf, len, 0);
  }
}
