struct pins {
  static const int latch = 8;
  static const int data = 11;
  static const int clock = 12;
  static const int layers[4] = {3, 4, 5, 6}; // not actually using 2!
};

void setup() {
  Serial.begin(115200);
  pinMode(pins::latch, OUTPUT);
  pinMode(pins::data, OUTPUT);
  pinMode(pins::clock, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(pins::layers[i], OUTPUT);
  }
}

void writeNum(int val) {
  digitalWrite(pins::latch, LOW);
  shiftOut(pins::data, pins::clock, MSBFIRST, val / 0b100000000);
  shiftOut(pins::data, pins::clock, MSBFIRST, val % 0b100000000);
  digitalWrite(pins::latch, HIGH);
}

void activateLayer(int num) {
  for (int j = 0; j < 4; j++) {
    digitalWrite(pins::layers[j], HIGH);
  }
  digitalWrite(pins::layers[num], LOW);
}

void activateLED(int x, int y, int z) {
  writeNum(0); // deactivate all pins
  activateLayer(z); // activate the requested layer, deactivate all others
  writeNum(pow(2, x + 4 * y));
}

void loop() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      activateLED(i, j, 0);
      delay(50);
    }
  }
}
