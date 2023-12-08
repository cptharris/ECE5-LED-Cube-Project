struct pins {
  static const int data = 11;
  static const int latch = 8;
  static const int clock = 12;
  static const int layers[];
};
const int pins::layers[] = { 7, 6, 5, 4 };

void setup() {
  Serial.begin(115200);
  pinMode(pins::latch, OUTPUT);
  pinMode(pins::data, OUTPUT);
  pinMode(pins::clock, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(pins::layers[i], OUTPUT);
  }
}

void writeNum(unsigned long val) {
  digitalWrite(pins::latch, LOW);
  shiftOut(pins::data, pins::clock, MSBFIRST, val >> 8);          // bit shift
  shiftOut(pins::data, pins::clock, MSBFIRST, val & 0b11111111);  // bit-wise and
  digitalWrite(pins::latch, HIGH);
}

void activateLayer(int num) {
  for (int j = 0; j < 4; j++) {
    digitalWrite(pins::layers[j], HIGH);
  }
  digitalWrite(pins::layers[num], LOW);
}

void activateLED(int x, int y, int z) {
  writeNum(0);       // deactivate all pins
  activateLayer(z);  // activate the requested layer, deactivate all others

  if (y == 0 && x == 0) {
    writeNum(1);
  } else if (y == 0 && x == 1) {
    writeNum(2);
  } else {
    writeNum((int)(pow(2, x) * pow(16, y)) + 1);
  }
}

void loop() {
  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        activateLED(x, y, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        activateLED(y, x, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        activateLED(l, y, x);
        delay(100);
      }
    }
  }
}
