//
// Created by alexium on 04.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PICTURE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PICTURE_H_

#include "Pixel.h"

typedef Pixel* **Picture;

extern Picture Picture_new(int width, int height);

extern Pixel Picture_get_pixel(Picture picture, int x, int y);

extern Pixel *Picture_get_pixel_ptr(Picture picture, int x, int y);

extern void Picture_set_pixel(Picture picture, int x, int y, Pixel *pixel);

#endif //SGM_SRC_ENGINE_RENDERS_2D_SCREEN_PICTURE_H_
