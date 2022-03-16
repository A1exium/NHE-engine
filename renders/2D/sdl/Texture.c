//
// Created by alexium on 06.03.2022.
//

#include "Texture.h"
#include <SDL2/SDL_image.h>
#include <stdarg.h>
#include "Render.h"

extern void *Texture_load(const char *file_name, Render *render) {

  SDL_Texture *txt;
  txt = IMG_LoadTexture(Render_get_sdlRenderer(render), file_name);
  return txt;
}
