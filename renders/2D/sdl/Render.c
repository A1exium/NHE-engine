//
// Created by alexium on 04.03.2022.
//

#include "Render.h"
#include <stdlib.h>
#include "Texture.h"
#include "../events/event_provider.h"

extern void provideEvents() {

  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    Event catched_event;
    switch (event.type)
    {
      case SDL_QUIT:
        exit(0);
        break;
      case SDL_KEYDOWN:
        catched_event.type = EventKeyboard;
        event_keyboard_set_key(&catched_event, event.key.keysym.sym);
        Event_throw(catched_event);
        break;
      default:
        break;
    }
  }
}

struct Render_s {
  Screen screen;
  TextureStorage textures;
  int width;
  int height;
  SDL_Renderer *renderer;
  SDL_Window *window;
};

SDL_Renderer *Render_get_sdlRenderer(Render render) {
  return render->renderer;
}

extern void render_set_textureStorage(Render render, TextureStorage texture_storage) {
  render->textures = texture_storage;
}

Render Render_new(Screen screen, TextureStorage texture_storage, int width, int height) {
  Render render =  malloc(sizeof(struct Render_s));
  render->height = height;
  render->textures = texture_storage;
  render->width = width;
  render->screen = screen;
  int renderer_flags = SDL_RENDERER_ACCELERATED;

  int window_flags = 0;

  render->window = SDL_CreateWindow("Main",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    width,
                                    height,
                                    window_flags
                                    );

  if (!render->window)
  {
    printf("Failed to open %d x %d window: %s\n", width, height, SDL_GetError());
    exit(1);
  }

  render->renderer = SDL_CreateRenderer(render->window, -1, renderer_flags);

  if (!render->renderer)
  {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    exit(1);
  }

  return render;
}

#include "../../globals/const.h"
#include "../objects/mod.h"

void render_render(Render render) {
  int ratio_x = render->width / AREA_MAX_X, ratio_y = render->height / AREA_MAX_Y;
  SDL_SetRenderDrawColor(render->renderer, 96, 128, 255, 255);
  SDL_RenderClear(render->renderer);
//  View *view = 0;
  foreach(View view = 0, view, render->screen) {
//    View *view = listItem_get(view_item);
    Position view_pos = view_get_pos(view);
    for (int x = view_pos.x; x < view_get_width(view); x++) {
      for (int y = view_pos.y; y < view_get_height(view); y++) {
        for (int z = 0; z < AREA_MAX_Z; z++) {
          GameObject cur_obj = view_get_GameObject(view, x, y, z);
          if (cur_obj) {
            SDL_Rect obj;
            Texture *cur_texture = textureStorage_get(render->textures, gameObject_get_type(cur_obj));
            obj.x = x * ratio_x;
            obj.y = y * ratio_y;
            SDL_QueryTexture(cur_texture, 0, 0, &obj.w, &obj.h);
            obj.w = ratio_x;
            obj.h = ratio_y;
            SDL_RenderCopy(render->renderer, cur_texture, 0, &obj);
          }
        }
      }
    }
  }
  SDL_RenderPresent(render->renderer);
}
