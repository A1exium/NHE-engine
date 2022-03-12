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
 * TODO
 * Добавляет GameObject на координаты (x, y)ю
 * Проверяет, есть ли там еще элемент. Если есть и у него НЕТ группы - отчищает память с ним.
 * Иначе заменяет его координаты
 * @param area Поле, на которое нужно добавить объект
 * @param game_object Добавляемый объект
 * @param z слой, на который нужно добавить обхект
 */
void Area_insert_GameObject(Area area, GameObject *game_object, int z);

/**
 * TODO
 * Двигает объект на дельту по координатам в 2D пространстве\n
 * <b>Сигнатура может измениться!</b>
 * @param obj Объект, который нужно сдвинуть
 * @param dx Сдвиг по x
 * @param dy Сдвиг по y
 */
extern void GameObject_move(GameObject *obj, Area area, int dx, int dy);

/**
 * TODO
 * "Телепортирует" объект на координаты
 * Сигнатура может измениться
 * @param obj Объект которому нужно поменять координаты
 * @param x новая координата по x
 * @param y новая координата по y
 */
extern void GameObject_teleport(GameObject *obj, Area area, int x, int y);

#endif //SGM_SRC_GAME_AREA_H_
