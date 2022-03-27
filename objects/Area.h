//
// Здесь функции для работы с GameObject *area[][]
//

#ifndef SGM_SRC_GAME_AREA_H_
#define SGM_SRC_GAME_AREA_H_

#include "GameObject.h"
typedef struct GameObject_s *GameObject;

/// <hr>
/// Дополнительная структура для хранения объектов. С ее помощью удобнее искать объекты по координатам.\n
/// <hr>
/// Текущая реализация - Трехмерный масив ссылок на \b GameObject
///
typedef struct Area_s *Area;

/**
 * Создает поле Area. <hr>
 * Сейчас заполняет его нулями(null-ами)
 * @param area сама Area - трехмерный массив(сейчас)
 */
extern Area Area_new(unsigned int size_X, unsigned int size_Y, unsigned int size_Z);

/**
 * Удаляет Area; \n
 * Не трогает объекты в ней
 * @param area
 */
extern void Area_free(Area area);

extern unsigned int Area_get_size_x(Area area);
extern unsigned int Area_get_size_y(Area area);
extern unsigned int Area_get_size_z(Area area);

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
 * Добавляет GameObject на координаты (x, y)ю
 * Проверяет, есть ли там еще элемент. Если есть и у него НЕТ группы - отчищает память с ним.
 * Иначе заменяет его координаты
 * @param area Поле, на которое нужно добавить объект
 * @param game_object Добавляемый объект
 * @param z слой, на который нужно добавить обхект
 * @returns Результат добавления: <br>
 * 1 - Ошибка \n
 * 0 - Ок
 */
extern int area_insert_GameObject(Area area, GameObject game_object);

#endif //SGM_SRC_GAME_AREA_H_
