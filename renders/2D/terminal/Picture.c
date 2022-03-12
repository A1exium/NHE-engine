//
// Created by alexium on 04.03.2022.
//

#include "Picture.h"
#include <stdlib.h>
#include "Pixel.h"
#include "2DArray.h"

Picture Picture_new(int width, int height) {
  Array2D_new_default(Pixel *, width, height, indexes, 0);
  return indexes;
}

Pixel Picture_get_pixel(Picture picture, int x, int y) {
  return *picture[x][y];
}

Pixel *Picture_get_pixel_ptr(Picture picture, int x, int y) {
  return picture[x][y];
}

void Picture_set_pixel(Picture picture, int x, int y, Pixel *pixel) {
  picture[x][y] = pixel;
//  picture[x][y]
}
