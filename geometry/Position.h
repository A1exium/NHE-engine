///
/// Структура позиции.
/**  В ней харнятся все, связанное с позицией:
 * Координаты
 * Движение
 * Направление взгляда
 * ...
 */
///

#ifndef SGM_SRC_GAME_POSITION_H_
#define SGM_SRC_GAME_POSITION_H_

/** @struct Position_s
 * Используется для хранения параметров и функций, связанных c Позицией объекта
 * @brief
 * Пока хранит только координаты
 * @var int \b x
 * - Координата по x
 * @var int \b y
 * - Координата по y
 * @var int z \b
 * - Слой, на котором расположен объект
 */
//struct Position_s;
struct Position_s {
  int x;
  int y;
  int z;
};
typedef struct Position_s Position;

/**
 * Создает объект типа Position
 * @param x - Координата по x
 * @param y - Координата по y
 * @param z - Координата по z
 * @return Созданный объект
 */
extern Position Position_new(int x, int y, int z);

/**
 * Меняет все координаты.
 * @param x
 * @param y
 * @param z
 * @return
 */
extern void Position_set(int x, int y, int z);

/**
 * Сдвигает каждую координату по заданным значениям
 * @param dx сдвиг по х
 * @param dy сдвиг по у
 * @param dz сдвиг по z
 */
extern void Position_move(int dx, int dy, int dz);

#endif //SGM_SRC_GAME_POSITION_H_
