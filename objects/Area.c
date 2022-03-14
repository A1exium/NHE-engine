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

GameObject *area_get(Area area, int x, int y, int z) {
  return area[x][y][z];
}

extern GameObject *area_pop(Area area, int x, int y, int z) {
  GameObject *obj = area[x][y][z];
  area[x][y][z] = 0;
  return obj;
}

extern GameObject *area_pop_object(Area area, GameObject *game_object) {
  Position pos = gameObject_get_pos(game_object);
  return area_pop(area, pos.x, pos.y, pos.z);
}

extern GameObject *area_get_by_object(Area area, GameObject *game_object) {
  Position pos = gameObject_get_pos(game_object);
  return area_get(area, pos.x, pos.y, pos.z);
}

extern int area_check_object(Area area, GameObject *game_object) {
  return game_object == area_get_by_object(area, game_object);
}

int area_insert_GameObject(Area area, GameObject *game_object) {
  Position pos = gameObject_get_pos(game_object);
  if (pos.x < AREA_MAX_X && pos.y < AREA_MAX_Y && pos.z < AREA_MAX_Z) {
    GameObject *ref =
        area[pos.x][pos.y][pos.z];
    if (ref == 0) {
      area[pos.x][pos.y][pos.z] = game_object;
      return 0;
    }
  }
  return 1;
}

int area_GameObject_move(GameObject *obj, Area area, int dx, int dy, int dz) {
  int ret_code = 0;
  if (area_check_object(area, obj)) {
    area_pop_object(area, obj);
    gameObject_change_cords(obj, dx, dy, dz);
    ret_code = area_insert_GameObject(area, obj);
  } else {
    gameObject_change_cords(obj, dx, dy, dz);
    if (area_get_by_object(area, obj) == 0) {
      ret_code = area_insert_GameObject(area, obj);
    }
  }
  return ret_code;
}
