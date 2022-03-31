//
// Created by alexium on 14.02.2022.
//

#include "Area.h"
#include <stdlib.h>
#include "GameObject.h"

struct Area_s {
  GameObject ***area;
  unsigned int sx;
  unsigned int sy;
  unsigned int sz;
};

Area Area_new(unsigned int size_X, unsigned int size_Y, unsigned int size_Z) {
  Area area = malloc(sizeof(struct Area_s));
  area->sx = size_X;
  area->sy = size_Y;
  area->sz = size_Z;
  area->area = calloc(size_X, sizeof(GameObject**));
  for (unsigned int x = 0; x < size_X; x++) {
    area->area[x] = calloc(size_Y, sizeof(GameObject*));
    for (unsigned int y = 0; y < size_Y; y++) {
      area->area[x][y] = calloc(size_Z, sizeof(GameObject));
    }
  }
  return area;
}

void Area_free(Area area) {
  for (unsigned int x = 0; x < area->sx; x++) {
    for (unsigned int y = 0; y < area->sy; y++) {
      free(area->area[x][y]);
    }
    free(area->area[x]);
  }
  free(area);
}

extern unsigned int Area_get_size_x(Area area) {
  return area->sx;
}
extern unsigned int Area_get_size_y(Area area) {
  return area->sy;
}
extern unsigned int Area_get_size_z(Area area) {
  return area->sz;
}

GameObject area_get(Area area, int x, int y, int z) {
  return area->area[x][y][z];
}

extern GameObject area_get_by_pos(Area area, Position position) {
  return area->area[position.x][position.y][position.z];
}

extern GameObject area_pop(Area area, int x, int y, int z) {
  GameObject obj = area->area[x][y][z];
//  gameObject_set_area(obj, 0);
  area->area[x][y][z] = 0;
  return obj;
}

extern GameObject area_pop_object(Area area, GameObject game_object) {
  Position pos = gameObject_get_pos(game_object);
  return area_pop(area, pos.x, pos.y, pos.z);
}

int area_insert_GameObject(Area area, GameObject game_object) {
  Position pos = gameObject_get_pos(game_object);
  if (pos.x < area->sx && pos.y < area->sy && pos.z < area->sz) {
    GameObject ref = area_get_by_pos(area, pos);
    if (ref == 0) {
      area->area[pos.x][pos.y][pos.z] = game_object;
//      gameObject_set_area(game_object, area);
      return 0;
    }
  }
  return 1;
}
