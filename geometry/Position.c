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

extern void position_set(Position *pos, int x, int y, int z) {
  pos->x = x;
  pos->y = y;
  pos->z = z;
}

extern void position_change_cords(Position *pos, int dx, int dy, int dz) {
  pos->x += dx;
  pos->y += dy;
  pos->z += dz;
}

extern int position_get_x(Position pos) {
  return pos.x;
}

extern int position_get_y(Position pos) {
  return pos.y;
}

extern int position_get_z(Position pos) {
  return pos.z;
}
