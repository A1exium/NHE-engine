//
// Вывод всего действа в консоль
//
#ifndef SGM_CMAKE_BUILD_DEBUG_VISUAL_H_
#define SGM_CMAKE_BUILD_DEBUG_VISUAL_H_

#include "../../../objects/Area.h"
#include "Picture.h"
#include "Pixel.h"

/**
 * <hr>
 * Выводит поле на экран
 * @param area Выводимое поле
 * @param height Размер выводимого изображения
 * @param width Размер выводимого изображения
 */
extern void print(Picture pic, int height, int width);

#endif //SGM_CMAKE_BUILD_DEBUG_VISUAL_H_
