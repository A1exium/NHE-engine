//
// Created by alexium on 31.03.2022.
//

#include "client_init.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "network/mod_pub.h"
#include "client.h"
#include "fcntl.h"

int CLIENT_SOCK_FD = 0;
int CLIENT_STATUS = 0;

int clientInit(char *addr, unsigned int port) {
  int ret_code = 0;
  CLIENT_SOCK_FD = socket(AF_INET, SOCK_STREAM, 0);
  if (CLIENT_SOCK_FD > 0) {
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(addr);
//    ret_code = inet_pton(AF_INET, addr, &serv_addr.sin_addr);
    ret_code = connect(CLIENT_SOCK_FD, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret_code == 0) {
      fcntl(CLIENT_SOCK_FD, F_SETFL, SOCK_STREAM | SOCK_NONBLOCK);
      CLIENT_STATUS = 1;
      send_event = sendEvent;
      return 0;
    }
    close(CLIENT_SOCK_FD);
    CLIENT_SOCK_FD = -1;
  }
  return ret_code;
}
