#include "Arduino.h"
#include "CubeControl.h"

CubeControl::CubeControl(int clock, int data, int latch, int layer1, int layer2, int layer3, int layer4) : clock(clock), data(data), latch(latch) {
  layers[0] = layer1;
  layers[1] = layer2;
  layers[2] = layer3;
  layers[3] = layer4;
}

void CubeControl::activate(int x, int y, int z) {
  write(0);       // deactivate all pins
  activateLayer(z);  // activate the requested layer, deactivate all others

  if (y == 0 && x == 0) {
    write(1);
  } else if (y == 0 && x == 1) {
    write(2);
  } else {
    write((int)(pow(2, x) * pow(16, y)) + 1);
  }
}

void CubeControl::begin() {
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(layers[i], OUTPUT);
  }
}

void CubeControl::write(unsigned long num) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, num >> 8);          // bit shift
  shiftOut(data, clock, MSBFIRST, num & 0b11111111);  // bit-wise and
  digitalWrite(latch, HIGH);
}

void CubeControl::activateLayer(unsigned int num) {
  for (int j = 0; j < 4; j++) {
    digitalWrite(layers[j], HIGH);
  }
  digitalWrite(layers[num], LOW);
}
