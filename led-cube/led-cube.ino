#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);
const int wait = 200;

void setup() {
  Serial.begin(115200);
  cube.begin();
  randomSeed(analogRead(0));
}

void rain(int numDrops, unsigned long dropTime, unsigned long timeRain);
void smile();
void randomMadness();
void Tower(int buildSpeed);

void loop() {
  // smile();
  // return;

  randomMadness();

  rain(8,100, 60000);

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

void rain(int numDrops, unsigned long dropTime, unsigned long timeRain) { 
  int drops[numDrops][3];
  unsigned long timeSinceDrop = 0;
  unsigned long startTime = millis();
  unsigned long timeSinceRainStart = millis();

  for(int i = 0; i < numDrops; i++){
    drops[i][0] = (int)random(0,3);
    drops[i][1] = (int)random(0,3);
    drops[i][2] = (int)random(0,3);
  }

  while(startTime + timeRain >= millis()){
    if(millis() - timeSinceDrop >= dropTime){
      
      timeSinceDrop = millis();
      for(int i = 0; i < numDrops; i++){
        drops[i][2]--;
        if(drops[i][2] < 0){
          drops[i][0] = (int)random(0,3);
          drops[i][1] = (int)random(0,3);
          drops[i][2] = 4;
        }
      } 
    }

    for(int i = 0; i < numDrops; i++){
      cube.activate(drops[i][0], drops[i][1], drops[i][2]);
    }
  }
  return;
}

void Tower(int buildSpeed){
  int layout[8][2] = {{0,1},{1,0},{2,0},{3,1},{3,2},{2,3},{1,3},{0,2}}; //Structure Im builder 
  int onLEDs[32][3]; // onLEDs[i][0] = -1 for off LED
  int LEDCounter = 0;
  unsigned long timeSinceLed = millis();

  for(int j = 0; j < 32; j++){ 
    onLEDs[j][0] = -1; // -1 means don't display 
  }

  while(LEDCounter < 33){  
    if(millis() - timeSinceLed >= buildSpeed){ //building the tower
    
      timeSinceLed = millis();
      onLEDs[LEDCounter][0] = layout[LEDCounter%8][0];
      onLEDs[LEDCounter][1] = layout[LEDCounter%8][1];
      onLEDs[LEDCounter][2] = LEDCounter/8;
      LEDCounter++;
      
    }

    for(int i = 0; i < 32 ; i++){ //displaying the tower
      if(onLEDs[i][0] != -1){
        cube.activate(onLEDs[i][0], onLEDs[i][1], onLEDs[i][2]);   
      } 
    }
  }
  return;
}
