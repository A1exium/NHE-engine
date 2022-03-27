///
/// Здесь Сама структура GameObject, И все функции для взаимодействия с ней
///

#ifndef SGM_SRC_GAME_GAMEOBJECT_H_
#define SGM_SRC_GAME_GAMEOBJECT_H_

#include "../geometry/Position.h"
#include "Area.h"
typedef struct Area_s *Area;

//! Всевозможные типы объектов
enum GameObjectType_t;

typedef int GameObjectType;

/** @struct s_GameObject GameObject.h GameObject.c
 * Основная структура. Каждый объект в игре является \b GameObject
 * @brief Содержит основную информацию об объекте.\n
 * Свойства отдельных типов Должны храниться в отдельных структурах
 */
/** @enum GameObjectType
 * - Все типы объектов перечислены здесь. \n
 * Используется для Определения типа объекта и логики для properties
 */
/** @var void \b *properties
 * - Здесь хранится указатель на структуру со свойствами объекта данного типа
 */
/** @var GameObjectType \b type
 * - Тип объекта
 */
/** @var Area \b area
 * - поле, где находится объект
 */
/** @var int \b x
 * - Координата по \p x
 */
/** @var int \b y
 * - Координата по \p y
 */
/** @var int \b z
 * - Координата по \p z ИЛИ слой снизу вверх.
 */
/** @typedef GameObject
 *  - Тип для удобного использования структуры
 */
struct GameObject_s;
typedef struct GameObject_s *GameObject;

/**
 * Создает новый объект и возвращает его
 * @param type Тип нового объекта
 * @param x координата x
 * @param y координата y
 * @param z слой.
 * @return Указатель на созданный \b GameObject
 */
extern GameObject GameObject_new(GameObjectType type, int x, int y, int z);

/**
 * Освобождает память объекта
 * @param gameobject Игровой объект
 */
extern void GameObject_free(GameObject game_object);

extern Area gameObject_get_area(GameObject game_object);

extern void gameObject_set_area(GameObject game_object, Area area);

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

/**
 * Заменяет позицию на заданную
 * @param obj объект
 * @param new_pos новая позиция
 * @returns 0 - Ок: \n;
 * 1 - Ошибка
 */
extern int gameObject_set_pos(GameObject obj, Position new_pos);

/**
 * Заменить координаты в объекте
 * @param obj объект
 * @param x
 * @param y
 * @param z
 * @returns 0 - Ок \n
 * 1 - Ошибка
 */
extern int gameObject_set_cords(GameObject obj, int x, int y, int z);

/**
 * Сдвинуть объект на координаты
 * @param obj объект
 * @param dx сдвиг по x
 * @param dy сдвиг по y
 * @param dz сдвиг по z
 * @returns 0 - Ок \n
 * 1 - Ошибка
 */
int gameObject_change_cords(GameObject obj, int dx, int dy, int dz);

#endif //SGM_SRC_GAME_GAMEOBJECT_H_
