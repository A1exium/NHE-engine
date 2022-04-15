//
// Created by alexium on 01.04.2022.
//

#include "server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void serverListen() {
  struct sockaddr_in cli_addr;
  int cli_fd = -1;
  if (listen(SERVER_SOCK_FD, 5) == 0) {
    unsigned int len = sizeof(cli_addr);
    if ((cli_fd = accept(SERVER_SOCK_FD, (struct sockaddr *)&cli_addr, &len)) >= 0) {
      int *boxed_cli_fd = malloc(sizeof(int));
      *boxed_cli_fd = cli_fd;
      int c_flags = fcntl(cli_fd, F_GETFL, 0);
      fcntl(cli_fd, F_SETFL, c_flags | SOCK_NONBLOCK);
      list_add(CONNECTIONS, boxed_cli_fd);
    }
  }
}

#include "events/Event.h"


void serverSendAll(char *data, unsigned int data_len) {
  if (data != 0 && data_len > 0) {
    foreach(int *client_send_fd, client_send_fd, CONNECTIONS) {
      send(*client_send_fd, data, data_len, 0);
    }
  }
}

void serverSendEvent(Event event, DataSealizingFunction serializing_function) {
  char buf[1024];
  ssize_t len = event_serialize(event, serializing_function, buf);
  serverSendAll(buf, len);
}

void serverServe() {
  int id = 0;
  foreach(int *client_fd, client_fd, CONNECTIONS) {
    char buf[1024];
    ssize_t readed = read(*client_fd, buf, 1024);
    if (readed > 0) {
      Event tmp = Event_new(EventServerMessage);
      event_deserialize(buf, &tmp);
      Event_throw(tmp);
      serverSendAll(buf, readed);
    }
    id++;
  }
}
