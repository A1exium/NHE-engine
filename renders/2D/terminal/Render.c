//
// Created by alexium on 04.03.2022.
//

#include "../base/Render.h"
#include <stdlib.h>
#include "../../../objects/GameObject.h"
#include "Texture.h"
#include "Picture.h"
#include "console.h"

struct Render_s {
  Screen screen;
  TextureStorage textures;
  int width;
  int height;
};

extern void render_set_textureStorage(Render *render, TextureStorage texture_storage) {
  render->textures = texture_storage;
}

Render *Render_new(Screen screen, TextureStorage texture_storage, int width, int height) {
  Render *render = (Render *) malloc(sizeof(Render));
  render->height = height;
  render->textures = texture_storage;
  render->width = width;
  render->screen = screen;
  return render;
}

const int TEXTURE_RATIO = 3;

#include <stdio.h>
#include "Pixel.h"

void render_render(Render *render) {

  printf("\033[1;1H\033[2J\n");

  Picture pic = Picture_new(render->width, render->height);
  foreach(view_item, render->screen) {
    View *view = listItem_get(view_item);
    Position view_pos = view_get_pos(view);
    for (int x = view_pos.x; x < view_get_width(view); x++) {
      for (int y = view_pos.y; y < view_get_height(view); y++) {
        for (int z = 0; z < AREA_MAX_Z; z++) {
          GameObject *cur_obj = view_get_GameObject(view, x, y, z);
          if (cur_obj) {

            Texture *cur_texture = textureStorage_get(render->textures, gameObject_get_type(cur_obj));

            for (int tx = 0; tx < TEXTURE_RATIO; tx++) {
              for (int ty = 0; ty < TEXTURE_RATIO; ty++) {
                Pixel cur_pixel = texture_get_pixel(cur_texture, tx, ty);
//                if (cur_pixel.symbol != ' ')
//                  picture_set_pixel(pic, x * TEXTURE_RATIO + tx, y * TEXTURE_RATIO + ty, cur_pixel);
                pixel_intersect_with(picture_get_pixel_ptr(pic, x * TEXTURE_RATIO + tx, y * TEXTURE_RATIO + ty), cur_pixel);
              }
            }
          }
        }
      }
    }
  }
  print(pic, render->height, render->width);
}
