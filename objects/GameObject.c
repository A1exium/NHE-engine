//
// Created by alexium on 14.02.2022.
//

#include "GameObject.h"
#include <stdlib.h>
#include "ListGameObject.h"
#include "../geometry/Position.h"

struct s_GameObject {
  GameObjectType type;
  ListGameObject *group;
  void *properties;
  Position pos;
};

GameObject *GameObject_new(GameObjectType type, int x, int y, int z) {
  GameObject *obj = (GameObject *) malloc(sizeof(GameObject));
  obj->type = type;
  obj->group = 0;
  obj->pos = Position_new(x, y, z);
  return obj;
}

GameObjectType gameObject_get_type(GameObject *obj) {
  return obj->type;
}

void gameObject_set_type(GameObject *obj, GameObjectType new_type) {
  obj->type = new_type;
}

extern Position gameObject_get_pos(GameObject *obj) {
  return obj->pos;
}

extern void gameObject_set_pos(GameObject *obj, Position new_pos) {
  obj->pos = new_pos;
}

extern void gameObject_set_cords(GameObject *obj, int x, int y, int z) {
  obj->pos.x = x;
  obj->pos.y = y;
  obj->pos.z = z;
}

int get_remainder(int num, int rem) {
  return (num * (-1 * (num < 0))) % rem;
}

void gameObject_change_cords(GameObject *obj, int dx, int dy, int dz) {
  obj->pos.x += dx;
  obj->pos.y += dy;
  obj->pos.z += dz;
}

void gameObject_free(GameObject *gameobject) {
  free(gameobject);
}
