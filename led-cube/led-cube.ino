#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);

void setup() {
  Serial.begin(115200);
  cube.begin();
}

void loop() {
  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(x, y, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(y, x, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(l, y, x);
        delay(100);
      }
    }
  }
}
