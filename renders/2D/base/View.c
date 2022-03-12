//
// Created by alexium on 02.03.2022.
//

#include "View.h"
#include <stdlib.h>

struct View_s {
  Area *area;
  Position pos;
  int width;
  int height;
};

View *View_new(Area *area, int x, int y, int width, int height) {
  View *view = (View *)malloc(sizeof(View));
  view->pos = Position_new(x, y, 0);
  view->height = height;
  view->area = area;
  view->width = width;
  return view;
}

Position View_get_pos(View *view) {
  return view->pos;
}

int View_get_width(View *view) {
  return view->width;
}

int View_get_height(View *view) {
  return view->height;
}

extern GameObject *View_get_GameObject(View *view, int x, int y, int z) {
  return (*view->area)[x][y][z];
}
