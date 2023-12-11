# ECE5 LED Cube Project

## Project Goal and Functionality

-   design an LED Cube with individually controllable LEDs
-   use shift registers to manage all the outputs
-   control the cube with an Arduino and program in cool sequences

The LED Cube features 64 individually controllable LEDs, arranged in a 4x4x4 cube. Every layer has a common cathode between the 16 LEDs in the layer. Every column of LEDs holds a column of common anodes. In this way, a single LED can be activated by 1) grounding its layer, and 2) powering its column. The 16 columns are wired to a parallel shift register combination. The two shift registers provide the 16 bits (2 bytes) to control the 16 columns. The layers are connected through a resistor to 4 digital output pins on the Arduino board.

## Hardware Components

-   64 LEDs
-   protoboard
-   4 (100Ω) resistors
-   2 shift registers
-   wire

## Tools

-   solder
-   wire cutter

## References

-   [4x4x4 LED Cube Arduino Uno - Instructables](https://www.instructables.com/4x4x4-LED-Cube-Arduino-Uno/)
-   [Shift Out Guide - Arduino](https://docs.arduino.cc/tutorials/communication/guide-to-shift-out) — includes parallel shift registers
