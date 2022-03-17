//
// Created by alexium on 16.03.2022.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void initCurrentRender() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, "#canvas");
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  IMG_Init(IMG_INIT_PNG);
  int state = SDL_ENABLE;
  SDL_EventState(SDL_TEXTINPUT, state);
  SDL_EventState(SDL_KEYDOWN, state);
  SDL_EventState(SDL_KEYUP, state);
  SDL_EventState(SDL_MOUSEMOTION, state);
  SDL_EventState(SDL_MOUSEBUTTONDOWN, state);
  SDL_EventState(SDL_MOUSEBUTTONUP, state);
}
