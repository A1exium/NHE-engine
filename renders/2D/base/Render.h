//
// Created by alexium on 04.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_
#define SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_

#include "View.h"
#include "Screen.h"
#include "TextureStorage.h"

struct Render_s;
typedef struct Render_s *Render;

extern Render Render_new(Screen screen, TextureStorage, int width, int height);

extern void Render_free(Render);

extern void render_set_textureStorage(Render render, TextureStorage);

extern void render_render(Render render);

#endif //SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_
