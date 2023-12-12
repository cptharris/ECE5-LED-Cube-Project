#include "Arduino.h"
#include "Point.h"

Point::Point(int x, int y, int z, int vx, int vy, int vz)
  : x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}

Point::Point() {
  x = (int)random(minC, maxC + 1);
  y = (int)random(minC, maxC + 1);
  z = (int)random(minC, maxC + 1);
  vx = ((int)random(0, 2) == 0) ? 1 : -1;
  vy = ((int)random(0, 2) == 0) ? 1 : -1;
  vz = ((int)random(0, 2) == 0) ? 1 : -1;
}

void Point::move() {
  // update position
  x += vx;
  y += vy;
  z += vz;

  // check and handle bouncing off bounds
  if (x < minC || x > maxC) {
    vx = -vx;                     // reverse velocity
    x = max(minC, min(x, maxC));  // clamp position within bounds
  }

  if (y < minC || y > maxC) {
    vy = -vy;
    y = max(minC, min(y, maxC));
  }

  if (z < minC || z > maxC) {
    vz = -vz;
    z = max(minC, min(z, maxC));
  }
}

int Point::getx() {
  return x;
}

int Point::gety() {
  return y;
}

int Point::getz() {
  return z;
}
