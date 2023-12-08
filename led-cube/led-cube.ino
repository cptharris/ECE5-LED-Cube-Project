#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);

void setup() {
  Serial.begin(115200);
  cube.begin();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch x, then y, then z
        cube.activate(k, j, i);
        delay(100);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch y, then x, then z
        cube.activate(j, k, i);
        delay(100);
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        // switch z, then y, then x
        cube.activate(i, j, k);
        delay(100);
      }
    }
  }
}
