//
// Created by FTE on 3/11/2022.
//
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

void initCurrentRender() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO | ICANON | O_NONBLOCK);
//  raw.c_lflag |= FNONBLOCK;
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}