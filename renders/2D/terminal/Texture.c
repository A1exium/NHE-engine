//
// Created by alexium on 06.03.2022.
//

#include "./Texture.h"
#include "../../../tools/2DArray.h"
#include "Pixel.h"
#include <stdio.h>

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

void texture_set_pixel(Texture *texture, Pixel pixel, int x, int y) {
  texture->pix[x][y] = pixel;
}

Pixel texture_get_pixel(Texture *texture, int x, int y) {
  return texture->pix[x][y];
}

//Pixel *texture_get_pixel_ptr(Texture *texture, int x, int y) {
//  return &texture->pix[x][y];
//}

#include "string.h"

char *fileName_add_ext(const char *file_name) {
  char *new_fname = malloc(sizeof(file_name) + sizeof(".nsd"));
  new_fname[0] = '\0';
  strcat(new_fname, file_name);
  strcat(new_fname, ".nsd");
  return new_fname;
}

extern void *Texture_load(Render *render, const char *file_name) {
//extern Texture *Texture_load(char *file_name) {
  int w, h;
  char *fname_with_ext = fileName_add_ext(file_name);
  FILE *file = fopen(fname_with_ext, "r");
  free(fname_with_ext);
  fscanf(file, "%d %d", &w, &h);
  fgetc(file);
  Texture *txt = Texture_new(w, h);
  txt->height = h;
  txt->width = w;
  for (int y = 0; y < w; y++) {
    for (int x = 0; x < h; x++) {
      char sym;
      int color, bg_color;
      fscanf(file, "-%c-%d-%d", &sym, &color, &bg_color);
      texture_set_pixel(txt, Pixel_from(sym, color, bg_color), x, y);
    }
    fgetc(file);
  }
  return txt;
}
