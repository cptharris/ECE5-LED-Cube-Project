#ifndef CubeControl_h
#define CubeControl_h

#include "Arduino.h"

class CubeControl {
public:
  CubeControl(int clock, int data, int latch, int layer1, int layer2, int layer3, int layer4);
  void activate(int x, int y, int z);
  void begin();
  void write(unsigned long num);
  unsigned long bin(int x, int y);
  void activateLayer(unsigned int num);
private:
  void off();
  int data, latch, clock;
  int layers[4];
};

#endif
