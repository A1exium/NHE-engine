//
// Created by alexium on 01.04.2022.
//

#include "server_init.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "network/mod_pub.h"
#include "network/server/server.h"

int SERVER_SOCK_FD = 0;
int SERVER_STATUS = 0;
List CONNECTIONS;

int serverInit(char *addr, unsigned int port) {
  if (!addr) addr = "0.0.0.0";
  if (port == 0) port = 48666;
  SERVER_SOCK_FD = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
  if (SERVER_SOCK_FD != 0) {
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(addr);
    servaddr.sin_port = htons(port);
    CONNECTIONS = List_new();
    if (bind(SERVER_SOCK_FD, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
      SERVER_STATUS = 1;
      send_event = serverSendEvent;
      return 0;
    }
    close(SERVER_SOCK_FD);
    SERVER_SOCK_FD = -1;
  }
  return 1;
}
