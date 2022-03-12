//
// Created by alexium on 04.03.2022.
//

#include "Pixel.h"
#include "renders/2D/terminal/win/ascii_colors.h"

Pixel Pixel_from(char sym, enum Colors color, enum Colors bg_color) {
  if (sym == 0) {
    sym = ' ';
  }
  Pixel pixel;
  pixel.symbol = sym;
  switch (bg_color) {
    case Red: {
      pixel.bg_color = REDB;
      break;
    }
    case Green: {
      pixel.bg_color = GRNB;
      break;
    }
    case Blue: {
      pixel.bg_color = BLUB;
      break;
    }
    case Black: {
      pixel.bg_color = BLKB;
      break;
    }
    default: {
      pixel.bg_color = "";
    }
  }switch (color) {
    case Red: {
      pixel.color = RED;
      break;
    }
    case Green: {
      pixel.color = GRN;
      break;
    }
    case Blue: {
      pixel.color = BLU;
      break;
    }
    case Black: {
      pixel.color = BLK;
      break;
    }
    default: {
      pixel.color = "";
    }
  }
  return pixel;
}

int Pixel_is_empty(Pixel *pix) {
  return pix->color == Transparent && pix->bg_color == Transparent;
}
