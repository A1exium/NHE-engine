//
// Created by alexium on 14.02.2022.
//

#include "Area.h"

void Area_init(Area area) {
  for (int x = 0; x < AREA_MAX_X; x++)
    for (int y = 0; y < AREA_MAX_Y; y++)
      for (int z = 0; z < AREA_MAX_Z; z++)
        area[x][y][z] = 0;
}

GameObject *area_get_object(Area area, int x, int y, int z) {
  return area[x][y][z];
}

extern GameObject *area_pop_object(Area area, int x, int y, int z) {
  GameObject *obj = area[x][y][z];
  area[x][y][z] = 0;
  return obj;
}

void area_insert_GameObject(Area area, GameObject *game_object) {
  area[gameObject_get_x(game_object)][gameObject_get_y(game_object)][gameObject_get_z(game_object)] = game_object;
}

int area_GameObject_move(GameObject *obj, Area area, int dx, int dy) {
  GameObject *area_obj = area_pop_object(area, gameObject_get_x(obj), gameObject_get_y(obj), gameObject_get_z(obj));
  if (obj == area_obj) {
    gameObject_move(obj, dx, dy);

    area_insert_GameObject(area, obj);
    return 0;
  }
  return 1;
}
