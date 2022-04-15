//
// Created by alexium on 27.03.2022.
//

#ifndef SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_
#define SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_

#include "../tools/List.h"

typedef struct Position_s Position;

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

/**
 * Возвращает объект по заданным координатам
 * @param area
 * @param x
 * @param y
 * @param z
 * @return объект по координатам
 */
extern GameObject area_get(Area area, int x, int y, int z);

/**
 * Возвращает объект по заданной позиции или 0, если там ничего нет
 * @param area
 * @param position
 * @return Объект или 0, если объекта нет
 */
extern GameObject area_get_by_pos(Area area, Position position);

/**
 * Удаляет объект с поля по заданным координатам и возвращает указатель на него
 * @param area
 * @param x
 * @param y
 * @param z
 * @return удаленный объект
 */
extern GameObject area_pop(Area area, int x, int y, int z);

/**
 * Удаляет объект с поля по самому объекту
 * @param area
 * @param game_object удаляемый объект
 * @return удаленный с поля объект
 */
extern GameObject area_pop_object(Area area, GameObject game_object);

/**
 * Возвращает тип объекта. Нужно для корректной работы других функций
 * @param obj Сам объект
 * @return Тип заданного объекта
 */
extern GameObjectType gameObject_get_type(GameObject obj);

/**
 * Возвращает позицию объекта
 * @param obj
 * @return позицию объекта
 */
extern Position gameObject_get_pos(GameObject obj);

extern void gameObject_move(GameObject game_object, int dx, int dy, int dz);

extern void GameObject_free(GameObject game_object);


extern unsigned int Area_get_size_x(Area area);
extern unsigned int Area_get_size_y(Area area);
extern unsigned int Area_get_size_z(Area area);

#endif //SGM_SRC_ENGINE_OBJECTS_MOD_PUB_H_
