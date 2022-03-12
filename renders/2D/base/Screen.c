//
// Created by alexium on 09.03.2022.
//

#include "Screen.h"

Screen Screen_new(View *view) {
  Screen screen = (Screen)List_new();
  List_add(screen, view);
  return screen;
}

void Screen_add_layer(Screen screen, View *view) {
  List_add(screen, view);
}
