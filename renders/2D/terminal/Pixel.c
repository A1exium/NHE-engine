//
// Created by alexium on 04.03.2022.
//

#include "Pixel.h"
#include "ascii_colors.h"

char *bgcolor_translate(enum Colors bgcolor) {
  switch (bgcolor) {
    case Red: {
      return REDB;
      break;
    }
    case Green: {
      return GRNB;
      break;
    }
    case Blue: {
      return BLUB;
      break;
    }
    case Black: {
      return BLKB;
      break;
    }
    default: {
      return "";
    }
  }
}

char *color_translate(enum Colors color) {
  switch (color) {
    case Red: {
      return RED;
      break;
    }
    case Green: {
      return GRN;
      break;
    }
    case Blue: {
      return BLU;
      break;
    }
    case Black: {
      return BLK;
      break;
    }
    default: {
      return "";
    }
  }
}

Pixel Pixel_from(char sym, enum Colors color, enum Colors bg_color) {
  if (sym == 0) {
    sym = ' ';
  }
  Pixel pixel;
  pixel.symbol = sym;
  pixel.bg_color = bgcolor_translate(bg_color);
  pixel.color = color_translate(color);
  return pixel;
}

int pixel_is_empty(Pixel *pix) {
  return pix->color == Transparent && pix->bg_color == Transparent;
}

void pixel_intersect_with(Pixel *pixel, Pixel new_pixel) {
  if (pixel->bg_color == bgcolor_translate(Transparent))
    pixel->bg_color = new_pixel.bg_color;
  if (pixel->color == color_translate(Transparent))
    pixel->color = new_pixel.color;
  if (new_pixel.symbol != ' ')
    pixel->symbol = new_pixel.symbol;
}
