//
// Created by alexium on 09.03.2022.
//

#include "Screen.h"

Screen Screen_new(View view) {
  Screen screen = (Screen)List_new();
  list_add(screen, view);
  return screen;
}

void Screen_add_layer(Screen screen, View *view) {
  list_add(screen, view);
}

extern void screen_free(Screen screen) {
  list_free(screen, (void (*)(void *)) view_free);
}
