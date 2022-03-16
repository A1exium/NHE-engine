//
// Created by alexium on 16.03.2022.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void initCurrentRender() {

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  IMG_Init(IMG_INIT_PNG);
}
