#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);
const int wait = 200;

void setup() {
  Serial.begin(115200);
  cube.begin();
  randomSeed(analogRead(0));
}

void rain(int numDrops);
void smile();
void randomMadness();

void loop() {
  // smile();
  // return;

  randomMadness();

  rain((int)random(2, 7));
  rain((int)random(2, 7));
  rain((int)random(2, 7));

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

void randomMadness() {
  for (int i = 0; i < 50; i++) {
    cube.activate((int)random(0, 4), (int)random(0, 4), (int)random(0, 4));
    delay(200);
  }
}

void smile() {
  cube.write(6);
  cube.activateLayer(0);
  cube.write(9);
  cube.activateLayer(1);
  cube.write(6);
  cube.activateLayer(3);
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
    delay(800);
  }
}
