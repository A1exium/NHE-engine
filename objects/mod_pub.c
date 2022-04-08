//
// Created by alexium on 27.03.2022.
//

#include "mod_pub.h"
#include "mod.h"

// Создает игровой объект(GameObject) и помещает его в список в зависимости от типа type;
GameObject createGameObject(Area area, GameObjectType type, int x, int y, int z, List class) {
  GameObject game_object = GameObject_new(type, x, y, z);
  if (area) {
    area_insert_GameObject(area, game_object);
    gameObject_set_area(game_object, area);
  }
  if (class) {
    list_add(class, game_object);
  }
  return game_object;
}

extern void gameObject_move(GameObject game_object, int dx, int dy, int dz) {
  gameObject_change_cords(game_object, dx, dy, dz);
}
