//
// Created by alexium on 28.03.2022.
//

#include "../../../events/event_provider.h"

#include <Windows.h>
#include <stdio.h>

extern void provideEvents() {
  int tmp = '\0';
  if (_kbhit() && (tmp = _getch()) != EOF) {
    Event event;
    event.type = Keyboard;
    event.key = tmp;
    Event_throw(event);
  }
}
