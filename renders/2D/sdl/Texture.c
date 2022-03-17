//
// Created by alexium on 06.03.2022.
//

#include "Texture.h"
#include <SDL2/SDL_image.h>
#include "Render.h"

extern void *Texture_load(Render *render, const char *file_name) {

  SDL_Texture *txt;
  txt = IMG_LoadTexture(Render_get_sdlRenderer(render), file_name);
  return txt;
}
