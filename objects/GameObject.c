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

void GameObject_set_type(GameObject *obj, GameObjectType new_type) {
  obj->type = new_type;
}
