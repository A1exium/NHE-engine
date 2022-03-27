//
// Created by alexium on 02.03.2022.
//

#include "View.h"
#include <stdlib.h>

struct View_s {
  Area area;
  Position pos;
  int width;
  int height;
};

View View_new(Area area, int x, int y, int width, int height) {
  View view = malloc(sizeof(struct View_s));
  view->pos = Position_new(x, y, 0);
  view->height = height;
  view->area = area;
  view->width = width;
  return view;
}

void view_free(View view) {
  free(view);
}

Position view_get_pos(View view) {
  return view->pos;
}

int view_get_width(View view) {
  return view->width;
}

int view_get_height(View view) {
  return view->height;
}

extern GameObject view_get_GameObject(View view, int x, int y, int z) {
  return area_get(view->area, x, y, z);
}
