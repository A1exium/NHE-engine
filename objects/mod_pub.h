//
// Created by alexium on 27.03.2022.
//

#ifndef SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_
#define SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_

#include "../tools/List.h"

enum GameObjectType_t;

typedef int GameObjectType;

struct GameObject_s;
typedef struct GameObject_s *GameObject;

typedef struct Area_s *Area;

/**
 * Создает игровой объект(GameObject) и помещает его в список class, а также в двумерный массив area;
 * @param type Тип игрового объекта
 * @param x координата по х
 * @param y координата по y
 * @param area двумерный массив указателей на GameObject - Может быть Null(0).
 * @param class Список указателей на GameObject - Может быть Null(0).
 * @return возвращает указатель на созданный объект;
 */
extern GameObject createGameObject(Area area, GameObjectType type, int x, int y, int z, List group);

/**
 * Создает поле Area. <hr>
 * Сейчас заполняет его нулями(null-ами)
 * @param area сама Area - трехмерный массив(сейчас)
 */
extern Area Area_new(unsigned int size_X, unsigned int size_Y, unsigned int size_Z);

extern void gameObject_move(GameObject, int dx, int dy, int dz);

#endif //SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_
