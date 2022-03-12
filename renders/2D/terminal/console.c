//
// Created by alexium on 11.02.2022.
//

#include "console.h"
#include <stdio.h>
#include "renders/2D/terminal/win/ascii_colors.h"

void print(Picture pic, int height, int width) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      Pixel tmp = Picture_get_pixel(pic, x, y);
//      puts(tmp.bg_color);
//      puts(tmp.color);
//      putchar(tmp.symbol);
      printf("%s%s%c%s", tmp.bg_color, tmp.color, tmp.symbol, reset);
//      puts(" ");
    }
    putchar('\n');
  }
}