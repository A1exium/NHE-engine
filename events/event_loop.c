//
// Created by alexium on 18.03.2022.
//

#include "event_loop.h"
#include "../renders/2D/base/Render.h"
#include "mod.h"

#include <stdlib.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#elif WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

void sleep_ms(int milliseconds){ // cross-platform sleep function
#ifdef __EMSCRIPTEN__
  emscripten_sleep(milliseconds);
#elif WIN32
  Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
  struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
#else
  if (milliseconds >= 1000)
      sleep(milliseconds / 1000);
    usleep((milliseconds % 1000) * 1000);
#endif
}

extern Render GLOBAL_RENDER;

_Noreturn void start_event_loop() {
  Event loop_event;
  loop_event.type = LoopEvent;
  while (1 + 1 == 2) {
    render_render(GLOBAL_RENDER);
    provideEvents();
    Event_throw(loop_event);
    Event event;
    while (Event_drain(&event)) {
      listeningTable_call(event);
    }
    sleep_ms(100);
  }
}
