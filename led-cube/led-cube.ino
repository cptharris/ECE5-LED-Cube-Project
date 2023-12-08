#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);
const int wait = 200;

void setup() {
  Serial.begin(115200);
  cube.begin();
}

void rain(int numDrops);

void loop() {
  rain(2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch x, then y, then z
        cube.activate(k, j, i);
        delay(wait);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch y, then x, then z
        cube.activate(j, k, i);
        delay(wait);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch z, then y, then x
        cube.activate(i, j, k);
        delay(wait);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch z, then x, then y
        cube.activate(i, k, j);
        delay(wait);
      }
    }
  }
}

void rain(int numDrops) {
  int sum = 0;
  int h = 3;
  for (int i = 0; i < numDrops; i++) {
    sum += cube.bin((int)random(0, 4), (int)random(0, 4));
  }
  while (h >= 0) {
    cube.activateLayer(h--);
    cube.write(sum);
    delay(1000);
  }
}
