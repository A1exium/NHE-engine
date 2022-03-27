//
// Created by alexium on 06.03.2022.
//

#include "./Texture.h"
#include "../../../tools/2DArray.h"
#include "Pixel.h"
#include <stdio.h>
#include "Render.h"

struct Texture_s {
  Pixel **pix;
  int width;
  int height;
};

extern Texture *Texture_new(int width, int height) {
  Texture *texture = (Texture *)malloc(sizeof(Texture));
  Array2D_new(Pixel, width, height, pix);
//  Pixel **pix = calloc(width, sizeof(Pixel *));
//  for (int i = 0; i < width; i++) {
//    pix[i] = calloc(height, sizeof(Pixel));
//  }
  texture->pix = pix;
  texture->width = width;
  texture->height = height;
  return texture;
}

void texture_set_pixel(Texture *texture, Pixel pixel, int x, int y) {
//  texture->pix[x][y] = pixel;

  texture->pix[x][y].symbol = pixel.symbol;
  texture->pix[x][y].color = pixel.color;
  texture->pix[x][y].bg_color = pixel.bg_color;
}

Pixel texture_get_pixel(Texture *texture, int x, int y) {
  return texture->pix[x][y];
}

//Pixel *texture_get_pixel_ptr(Texture *texture, int x, int y) {
//  return &texture->pix[x][y];
//}

//#include "string.h"
//
//char *fileName_add_ext(const char *file_name) {
//  char *new_fname = malloc(sizeof(file_name) + sizeof(".nsd") - sizeof(char));
//  new_fname[0] = '\0';
//  strcat(new_fname, file_name);
//  strcat(new_fname, ".nsd");
//  return new_fname;
//}

extern void *Texture_load(Render render, const char *file_name) {
//extern Texture *Texture_load(char *file_name) {
  int w, h;
//  char *fname_with_ext = fileName_add_ext(file_name);
  FILE *file = fopen(file_name, "r");
//  free(fname_with_ext);
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

extern void texture_from_texture(Texture *dest_texture, Texture *texture) {
  int every_pixel_dupe_x;
  int every_pixel_dupe_y;
  int new_width = dest_texture->width;
  int new_height = dest_texture->height;
  if (new_width >= texture->width) {
    every_pixel_dupe_x = new_width / texture->width;
  }
  if (new_height >= texture->height) {
    every_pixel_dupe_y = new_height / texture->height;
  }
  for (int old_x = 0; old_x < texture->width; old_x++) {
    for (int old_y = 0; old_y < texture->height; old_y++) {

      for (int num_x = 0; num_x < every_pixel_dupe_x; num_x++) {
        for (int num_y = 0; num_y < every_pixel_dupe_y; num_y++) {
          texture_set_pixel(dest_texture,
                            texture_get_pixel(
                                texture,
                                old_x,
                                old_y
                            ),
                            old_x * every_pixel_dupe_x + num_x,
                            old_y * every_pixel_dupe_y + num_y
          );
        }
      }
    }
  }
}

extern Texture *texture_scale(Texture *texture, int new_width, int new_height) {
  Texture *new_texture = Texture_new(new_width, new_height);
  texture_from_texture(new_texture, texture);
  return new_texture;
}


extern void texture_free(Texture *texture) {
  for (int x = 0; x < texture->width; x++) {
    free(texture->pix[x]);
  }
  free(texture->pix);
  free(texture);
}

extern int texture_get_width(Texture *texture) {
  return texture->width;
}

extern int texture_get_height(Texture *texture) {
  return texture->height;
}
