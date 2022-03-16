cmake_minimum_required(VERSION 3.17)
project(NHE C)

set(CMAKE_C_STANDARD 11)

add_library(NHE SHARED
        tools/List.c tools/List.h
        tools/2DArray.c tools/2DArray.h
        tools/serializer.c tools/serializer.h
        geometry/Position.c geometry/Position.h
        geometry/mod.h
        objects/Area.c objects/Area.h
        objects/GameObject.c objects/GameObject.h
        objects/ListGameObject.c objects/ListGameObject.h
        objects/mod.c objects/mod.h
        renders/2D/base/Screen.c
        renders/2D/base/TextureStorage.c
        renders/2D/base/View.c
        renders/2D/mod.h
        )

add_subdirectory(renders/2D/terminal)
target_include_directories(NHE PUBLIC tools)
# TODO: Remove const from engine
target_include_directories(NHE PRIVATE ../globals)

set_target_properties(NHE PROPERTIES PUBLIC_HEADER engine.h)

# Build with terminal graphics
target_link_libraries(NHE Term-graphics)