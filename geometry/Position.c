//
// Created by alexium on 26.02.2022.
//

#include "Position.h"

//struct Position_s {
//  int x;
//  int y;
//  int z;
//};

Position Position_new(int x, int y, int z) {
  Position pos;
  pos.y = y;
  pos.x = x;
  pos.z = z;
  return pos;
}
