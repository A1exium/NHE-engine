//
// Created by alexium on 16.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURE_H_

#include "Render.h"
#define IMG_EXT

extern void *Texture_load(Render render, const char *file_name);
char *fileName_add_ext(const char *file_name);
#define get_asset_path(file) "assets/" file "." IMG_EXT

#endif //SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURE_H_
