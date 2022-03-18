//
// Created by alexium on 14.03.2022.
//

#include "TextureStorage.h"
#include <stdlib.h>

TextureStorage TextureStorage_new(int capacity) {
  return malloc(sizeof(void *) * capacity);
}

extern void textureStorage_free(TextureStorage texture_storage) {
  free(texture_storage);
}

void *textureStorage_get(TextureStorage texture_storage, GameObjectType type) {
  return texture_storage[type];
}

void textureStorage_insert(TextureStorage ts, GameObjectType type, void *texture) {
  ts[type] = texture;
}
