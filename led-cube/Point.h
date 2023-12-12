#ifndef Point_h
#define Point_h

#include "Arduino.h"

class Point {
public:
  Point();
  Point(int x, int y, int z, int vx, int vy, int vz);
  // function to update the position based on velocity and bounce off bounds
  void move();
  int getx();
  int gety();
  int getz();

private:
  int x, y, z;
  int vx, vy, vz;
  static const int minC = 0;
  static const int maxC = 3;
};

#endif
