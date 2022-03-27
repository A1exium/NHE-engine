//
// Created by alexium on 14.02.2022.
//

#include "GameObject.h"
#include <stdlib.h>
#include "../geometry/Position.h"

struct GameObject_s {
  GameObjectType type;
  Area area;
  void *properties;
  Position pos;
};

GameObject GameObject_new(GameObjectType type, int x, int y, int z) {
  GameObject obj = malloc(sizeof(struct GameObject_s));
  obj->type = type;
  obj->area = 0;
  obj->pos = Position_new(x, y, z);
  return obj;
}

GameObjectType gameObject_get_type(GameObject obj) {
  return obj->type;
}

void gameObject_set_type(GameObject obj, GameObjectType new_type) {
  obj->type = new_type;
}

Position gameObject_get_pos(GameObject obj) {
  return obj->pos;
}

int gameObject_set_cords(GameObject obj, int x, int y, int z) {
  if (obj->area) {
    if (area_get(obj->area, x, y, z) == 0) {
      Area tmp_area = obj->area;
      area_pop_object(tmp_area, obj);
      position_set(&obj->pos, x, y, z);
      area_insert_GameObject(tmp_area, obj);
      return 0;
    }
    return 1;
  } else {
    position_set(&obj->pos, x, y, z);
    return 0;
  }
}

int gameObject_set_pos(GameObject obj, Position new_pos) {
  return gameObject_set_cords(obj, new_pos.x, new_pos.y, new_pos.z);
}

int gameObject_change_cords(GameObject obj, int dx, int dy, int dz) {
  Position tmp_pos = obj->pos;
  position_change_cords(&tmp_pos, dx, dy, dz);
  return gameObject_set_pos(obj, tmp_pos);
}

void GameObject_free(GameObject gameobject) {
  free(gameobject);
}

extern Area gameObject_get_area(GameObject game_object) {
  return game_object->area;
}

extern void gameObject_set_area(GameObject game_object, Area area) {
  game_object->area = area;
}
