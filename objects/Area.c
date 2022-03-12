//
// Created by alexium on 14.02.2022.
//

#include "Area.h"

void Area_init(Area area) {
  for (int x = 0; x < AREA_MAX_X; x++)
    for (int y = 0; y < AREA_MAX_Y; y++)
      for (int z = 0; z < AREA_MAX_Z; z++)
        area[x][y][z] = 0;
}
