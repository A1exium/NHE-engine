//
// Created by alexium on 06.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_

#include "Pixel.h"
#include "../base/Texture.h"

struct Texture_s;
typedef struct Texture_s Texture;

Texture *Texture_new(int width, int height);

extern void texture_set_pixel(Texture *texture, Pixel pixel, int x, int y);

extern Pixel texture_get_pixel(Texture *texture, int x, int y);

extern void texture_from_texture(Texture *dest_texture, Texture *texture);

extern Texture *texture_scale(Texture *texture, int new_width, int new_height);

extern int texture_get_width(Texture *texture);

extern int texture_get_height(Texture *texture);

extern void texture_free(Texture *texture);
//extern Pixel *texture_get_pixel_ptr(Texture *texture, int x, int y);

#endif //SGM_SRC_ENGINE_RENDERS_2D_DEFAULT_TEXTURE_H_
