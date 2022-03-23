cmake_minimum_required(VERSION 3.17)
project(SDL-graphics C)

set(CMAKE_C_STANDARD 11)

add_library(SDL-graphics STATIC
        Render.c
        Texture.c Texture.h
        init_sdl.c
        export/texture_formats.h)

target_include_directories(SDL-graphics PUBLIC ./export)

if(EMSCRIPTEN)
    target_compile_options(SDL-graphics PUBLIC -sUSE_SDL=2 -sUSE_SDL_IMAGE=2)
#    target_compile_options(SDL-graphics PUBLIC -O3)
    target_link_options(SDL-graphics PUBLIC -sUSE_SDL=2 -sUSE_SDL_IMAGE=2)
    target_link_options(SDL-graphics PUBLIC -sSDL2_IMAGE_FORMATS=["png"])
#    target_link_options(SDL-graphics PUBLIC -O3)
else()
    target_link_libraries(SDL-graphics ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
endif()

target_include_directories(SDL-graphics PRIVATE ../base)
target_include_directories(SDL-graphics PUBLIC ../../../tools)
