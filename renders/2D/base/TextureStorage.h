//
// Created by alexium on 14.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_

#include "../../../objects/GameObject.h"

typedef void **TextureStorage;

TextureStorage TextureStorage_new(int capacity);

void *textureStorage_get(TextureStorage texture_storage, GameObjectType type);

void textureStorage_insert(TextureStorage ts, GameObjectType type, void *texture);

#endif //SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_
