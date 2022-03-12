//
// Created by alexium on 14.02.2022.
//

#include "mod.h"

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
GameObject *createObject(GameObjectType type, int x, int y, int z, Area area, ListGameObject class) {
  GameObject *game_object = GameObject_new(type, x, y, z);
  if (area) {
    area[x][y][z] = game_object;
  }
  if (class) {
    ListGameObject_add(class, game_object);
  }
  return game_object;
}
