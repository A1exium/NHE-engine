//
// Created by alexium on 06.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../base/Texture.h"
#include "Render.h"

#define IMG_EXT "png"

typedef SDL_Texture Texture;
extern void *Texture_load(Render *render, const char *file_name);

#endif //SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_
