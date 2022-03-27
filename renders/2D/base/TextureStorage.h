//
// Created by alexium on 14.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_
#define SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_

//#include "../../../objects/GameObject.h"
typedef struct GameObject_s *GameObject;
typedef int GameObjectType;

typedef void **TextureStorage;

extern TextureStorage TextureStorage_new(int capacity);

extern void textureStorage_free(TextureStorage);

void *textureStorage_get(TextureStorage texture_storage, GameObjectType type);

extern void textureStorage_insert(TextureStorage ts, GameObjectType type, void *texture);

#endif //SGM_SRC_ENGINE_RENDERS_2D_BASE_TEXTURESTORAGE_H_
