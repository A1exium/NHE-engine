//
// Created by alexium on 06.03.2022.
//

#include "Texture.h"
#include <SDL2/SDL_image.h>
#include "Render.h"

//#include "string.h"

//char *fileName_add_ext(const char *file_name) {
//  char *new_fname = malloc(sizeof(file_name) + sizeof(".png"));
//  new_fname[0] = '\0';
//  strcat(new_fname, file_name);
//  strcat(new_fname, ".png");
//  return new_fname;
//}
//
extern void *Texture_load(Render render, const char *file_name) {

  SDL_Texture *txt;
//  char *fname_with_ext = fileName_add_ext(file_name);
  txt = IMG_LoadTexture(Render_get_sdlRenderer(render), file_name);
//  free(fname_with_ext);
  return txt;
}
