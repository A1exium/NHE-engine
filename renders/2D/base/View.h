//
/// Здесь описывается структура "взгляда" на поле - Взятие части поля
//

#ifndef SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
#define SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_

#include "../../../objects/Area.h"
#include "../../../geometry/Position.h"

/** @struct View_s View.h View.c
 * Структура, которая хранит в себе прямоугольный участок(область) Area заданного размера по заданным координатам.
 */
/** @var Area \b *area
 * - Указатель на Area, с которой берется View
 */
/** @var Position \b pos
 * - Координаты участка
 */
/** @var int \b width
 * - Ширина участка
 */
/** @var int \b height
 * - Высота участка
 */
/** @typedef View
 *  - Тип для удобного использования структуры
 */
typedef struct View_s View;

/**
 * TODO: Стандартизируйте координаты!
 * Создает новый участок View и возращает его указатель
 * @param area - Area, с которой брать участок
 * @param x - координата x правого верхнего угла
 * @param y - координата y правого верхнего угла
 * @param width - длина участка
 * @param height - высота участка
 * @return - указатель на View(участок)
 */
extern View *View_new(Area *area, int x, int y, int width, int height);

/**
 * Возвращает позицию участка
 * Атрибут \b pos у структуры
 * @param view - Участок, позиция которого нужна
 * @return Позиция участка
 */
extern Position View_get_pos(View *view);

/**
 * Возвращает ширину участка
 * @param view - Участок
 * @return ширину участка
 */
extern int View_get_width(View *view);

/**
 * Возвращает высоту участка
 * @param view - Участок
 * @return высоту участка
 */
extern int View_get_height(View *view);

/**
 * Возвращает объект из Участка
 * Координаты указываются относительно View(участка)
 * @param view - Участок
 * @param x - Координата \p x в этом участке
 * @param y - Координата \p y в этом участке
 * @param z - Координата \p z (слой) в Area[x][y]
 * @return Ссылка на игровой объект
 */
extern GameObject *View_get_GameObject(View *view, int x, int y, int z);

#endif //SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
