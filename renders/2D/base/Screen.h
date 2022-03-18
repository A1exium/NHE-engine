//
// Created by alexium on 09.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_BASE_SCREEN_H_
#define SGM_SRC_ENGINE_RENDERS_2D_BASE_SCREEN_H_

#include "View.h"
#include "List.h"

/**
 * Экран - Абстракция для наложения нескольких View друг на друга
 */
typedef List *Screen;

/**
 * Создает новый "Экран" с заданным View
 * @param view
 * @return
 */
extern Screen Screen_new(View *view);

extern void screen_free(Screen);

/**
 * Добавляет новый View на экран
 * @param view ссылка на добавляемый View
 */
extern void screen_add_layer(Screen, View *);

#endif //SGM_SRC_ENGINE_RENDERS_2D_BASE_SCREEN_H_
