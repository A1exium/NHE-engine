cmake_minimum_required(VERSION 3.17)
project(SDL-graphics C)

set(CMAKE_C_STANDARD 11)


add_library(SDL-graphics STATIC
        Render.c
        Texture.c Texture.h
        init_sdl.c
        )
#find_package(SDL2)
include(FindPkgConfig)
#
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED sdl2_image)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(SDL-graphics ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

target_include_directories(SDL-graphics PRIVATE ../base)
target_include_directories(SDL-graphics PUBLIC ../../../tools)
