#ifndef CubeControl_h
#define CubeControl_h

#include "Arduino.h"

class CubeControl {
public:
  CubeControl(int clock, int data, int latch, int layer1, int layer2, int layer3, int layer4);
  // specify (x,y,z) coordinate (begins at 0) to activate
  void activate(int x, int y, int z);
  // sets up the Cube pins
  void begin();
  // write a binary number to the shift registers
  void write(unsigned long num);
  // get a binary number for the specified (x,y) coordinate
  unsigned long bin(int x, int y);
  // turn on a layer, turn off all others; specify an invalid layer to turn off all layers
  void activateLayer(unsigned int num);

  /* -----ANIMATIONS----- */

  // snake - different values of n snake differently
  void animateSnake(int n = 1, int wait = 150);
  // randomMadness - randomly turn on n pixels, one after another
  void randomMadness(int n, int wait = 200);
private:
  void off();
  int data, latch, clock;
  int layers[4];
};

#endif
