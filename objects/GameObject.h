///
/// Здесь Сама структура GameObject, И все функции для взаимодействия с ней
///

#ifndef SGM_SRC_GAME_GAMEOBJECT_H_
#define SGM_SRC_GAME_GAMEOBJECT_H_

//! Всевозможные типы объектов
enum GameObjectType_t;
//typedef enum GameObjectType_t GameObjectType;
typedef enum GameObjectType_t {
  None,
  Tile,
  Player,
  Nishal,
} GameObjectType;

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
/** @var ListGameObject \b *group
 * - Массив / Множество, где хранится объект помимо \b Area
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
struct s_GameObject;
typedef struct s_GameObject GameObject;

/**
 * Создает новый объект возвращает указатель на него
 * @param type Тип нового объекта
 * @param x координата x
 * @param y координата y
 * @param z слой.
 * @return Указатель на созданный \b GameObject
 */
extern GameObject *GameObject_new(GameObjectType type, int x, int y, int z);

/**
 * TODO
 * Освобождает память объекта, удаляет его из всех связанных с ним структур(из area, из group)
 * @param gameobject Игровой объект
 */
extern void GameObject_free(GameObject *gameobject);

/**
 * Возвращает тип объекта. Нужно для корректной работы других функций
 * @param obj Сам объект
 * @return Тип заданного объекта
 */
extern GameObjectType gameObject_get_type(GameObject *obj);

/**
 * TODO
 * Двигает объект на дельту по координатам в 2D пространстве\n
 * <b>Сигнатура может измениться!</b>
 * @param obj Объект, который нужно сдвинуть
 * @param dx Сдвиг по x
 * @param dy Сдвиг по y
 */
extern void GameObject_move(GameObject *obj, int dx, int dy);

/**
 * TODO
 * "Телепортирует" объект на координаты
 * Сигнатура может измениться
 * @param obj Объект которому нужно поменять координаты
 * @param x новая координата по x
 * @param y новая координата по y
 */
extern void GameObject_teleport(GameObject *obj, int x, int y);

#endif //SGM_SRC_GAME_GAMEOBJECT_H_
