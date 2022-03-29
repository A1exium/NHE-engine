//
// Created by alexium on 28.03.2022.
//

#include "../../../events/event_provider.h"

#include <unistd.h>

extern void provideEvents() {
  int tmp = '\0';
  while (read(STDIN_FILENO, &tmp, 1) == 1) {
    Event event;
    event.type = Keyboard;
    event.key = tmp;
    Event_throw(event);
  }
}
