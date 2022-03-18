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

int render_get_width(Render *render) {
  return render->width;
}
int render_get_height(Render *render) {
  return render->height;
}

Render *Render_new(Screen screen, TextureStorage texture_storage, int width, int height) {
  Render *render = (Render *) malloc(sizeof(Render));
  render->height = height;
  render->textures = texture_storage;
  render->width = width;
  render->screen = screen;
  return render;
}

//const int TEXTURE_RATIO = 3;

#include <stdio.h>
#include "Pixel.h"

void render_render(Render *render) {

  printf("\033[1;1H\033[2J\n");

  Picture pic = Picture_new(render->width, render->height);
  foreach(view_item, render->screen) {
    View *view = listItem_get(view_item);
    Position view_pos = view_get_pos(view);
    Texture *cur_texture = Texture_new(render_get_width(render) / view_get_width(view), render_get_height(render) / view_get_height(view));
    for (int x = view_pos.x; x < view_get_width(view); x++) {
      for (int y = view_pos.y; y < view_get_height(view); y++) {
        for (int z = 0; z < AREA_MAX_Z; z++) {
          GameObject *cur_obj = view_get_GameObject(view, x, y, z);
          if (cur_obj) {

            texture_from_texture(cur_texture, textureStorage_get(render->textures, gameObject_get_type(cur_obj)));

            int TEXTURE_RATIO_X = texture_get_width(cur_texture);
            int TEXTURE_RATIO_Y = texture_get_height(cur_texture);
            for (int tx = 0; tx < TEXTURE_RATIO_X; tx++) {
              for (int ty = 0; ty < TEXTURE_RATIO_Y; ty++) {
                Pixel cur_pixel = texture_get_pixel(cur_texture, tx, ty);
                pixel_intersect_with(picture_get_pixel_ptr(pic, x * TEXTURE_RATIO_X + tx, y * TEXTURE_RATIO_Y + ty), cur_pixel);
              }
            }
          }
        }
      }
    }
    texture_free(cur_texture);
  }
  print(pic, render->height, render->width);
}

extern void Render_free(Render *render) {
  free(render);
}
