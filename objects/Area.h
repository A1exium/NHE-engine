//
// Здесь функции для работы с GameObject *area[][]
//

#ifndef SGM_SRC_GAME_AREA_H_
#define SGM_SRC_GAME_AREA_H_

#include "GameObject.h"
#include "../../globals/const.h"

/// TODO: Дополнить + сделать красивее
/// <hr>
/// Дополнительная структура для хранения объектов. С ее помощью удобнее искать объекты по координатам.\n
/// <hr>
/// Текущая реализация - Трехмерный масив ссылок на \b GameObject
///
typedef GameObject *Area[AREA_MAX_X][AREA_MAX_Y][AREA_MAX_Z];

/**
 * Инициализирует массив Area. <hr>
 * Сейчас заполняет его нулями
 * @param area сама Area - трехмерный массив(сейчас)
 */
extern void Area_init(Area area);

/**
 * Возвращает объект по заданным координатам
 * @param area
 * @param x
 * @param y
 * @param z
 * @return объект по координатам
 */
extern GameObject *area_get(Area area, int x, int y, int z);

/**
 * Удаляет объект с поля по заданным координатам и возвращает указатель на него
 * @param area
 * @param x
 * @param y
 * @param z
 * @return удаленный объект
 */
extern GameObject *area_pop(Area area, int x, int y, int z);

/**
 * Удаляет объект с поля по самому объекту
 * @param area
 * @param game_object
 * @return указатель на удаленный объект
 */
extern GameObject *area_pop_object(Area area, GameObject *game_object);

/**
 * Проверяет, соответстввует ли объект на поле его координатам в game_object
 * @param area
 * @param game_object
 * @return Результат: <br>
 * 0 - не соответствует <br>
 * 1 - соответствует
 */
extern int area_check_object(Area area, GameObject *game_object);

/**
 * TODO
 * Добавляет GameObject на координаты (x, y)ю
 * Проверяет, есть ли там еще элемент. Если есть и у него НЕТ группы - отчищает память с ним.
 * Иначе заменяет его координаты
 * @param area Поле, на которое нужно добавить объект
 * @param game_object Добавляемый объект
 * @param z слой, на который нужно добавить обхект
 * @returns Результат добавления: <br>
 * 1 - Ошибка
 * 0 - Ок
 */
int area_insert_GameObject(Area area, GameObject *game_object);

/**
 * Двигает объект на дельту по координатам в 2D пространстве.\n
 * Проверяет на соответствие координат объекта его положунию на area.\n
 * - Если координаты объекта на area соответствуют координатам объекта, то сдвигает объект.\n
 * - Если объект "уходит с поля", то просто убирает его с прошлой позиции.
 * - Если объект "возвращается на поле" - отображаем его.
 * @param obj Объект, который нужно сдвинуть
 * @param dx Сдвиг по x
 * @param dy Сдвиг по y
 * @returns Результат сдвига: <br>
 * 0 - ОК<br>
 * 1 - Ошибка
 */
extern int area_GameObject_move(GameObject *obj, Area area, int dx, int dy, int dz);

/**
 * TODO
 * "Телепортирует" объект на координаты
 * Сигнатура может измениться
 * @param obj Объект которому нужно поменять координаты
 * @param x новая координата по x
 * @param y новая координата по y
 * @returns Результат телепорта: <br>
 * 0 - ОК <br>
 * 1 - Ошибка
 */
extern int area_GameObject_teleport(GameObject *obj, Area area, int x, int y, int z);

/**
 * Возвращает объект по координатам заданного объекта
 * @param area нужная area
 * @param game_object заданный объект
 * @return объект по координатам \b game_object
 */
extern GameObject *area_get_by_object(Area area, GameObject *game_object);
#endif //SGM_SRC_GAME_AREA_H_
