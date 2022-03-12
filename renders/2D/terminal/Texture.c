//
// Created by alexium on 06.03.2022.
//

#include "Texture.h"
#include "../../../tools/2DArray.h"
#include "Pixel.h"

struct Texture_s {
  Pixel **pix;
  int width;
  int height;
};

extern Texture *Texture_new(int width, int height) {
  Texture *texture = (Texture *)malloc(sizeof(Texture));
  Array2D_new(Pixel, width, height, pix);
  texture->pix = pix;
  return texture;
}

void Texture_set_pixel(Texture *texture, Pixel pixel, int x, int y) {
  texture->pix[x][y] = pixel;
}

Pixel Texture_get_pixel(Texture *texture, int x, int y) {
  return texture->pix[x][y];
}

Pixel *Texture_get_pixel_ptr(Texture *texture, int x, int y) {
  return &texture->pix[x][y];
}

extern Texture *Texture_load(FILE *file) {
  int w, h;
  fscanf(file, "%d %d", &w, &h);
  fgetc(file);
  Texture *txt = Texture_new(w, h);
  txt->height = h;
  txt->width = w;
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      char sym;
      int color, bg_color;
      fscanf(file, "-%c-%d-%d", &sym, &color, &bg_color);
      Texture_set_pixel(txt, Pixel_from(sym, color, bg_color), x, y);
    }
    fgetc(file);
  }
  return txt;
}
