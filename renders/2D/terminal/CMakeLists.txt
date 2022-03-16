cmake_minimum_required(VERSION 3.17)
project(Term-graphics C)

set(CMAKE_C_STANDARD 11)

add_library(Term-graphics STATIC
        colors.h
        console.c console.h
        Picture.c Picture.h
        Pixel.c Pixel.h
        Render.c
        Texture.c Texture.h
        )

target_include_directories(Term-graphics PRIVATE ../base)
target_include_directories(Term-graphics PUBLIC ../../../tools)

IF (WIN32)
    target_sources(Term-graphics PUBLIC win/init_term.c  ascii_colors.h)
    target_include_directories(Term-graphics PUBLIC win)
ELSE()
    target_sources(Term-graphics PUBLIC linx/init_term.c  linx/ascii_colors.h)
    target_include_directories(Term-graphics PUBLIC linx)
ENDIF()