/****************************************************************
RandomPixels.ino
LED Array 8x7 Charlieplex
Shawn Hymel @ SparkFun Electronics
February 9, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Randomly turn pixels on and off.

Hardware Connections:

IMPORTANT:  The Charlieplex LED board is designed for 2.0 - 5.2V!
            Higher voltages can damage the LEDs.

 Arduino Pin | Charlieplex Board
 ------------|------------------
      2      |         A
      3      |         B
      4      |         C
      5      |         D
      6      |         E
      7      |         F
      8      |         G
      9      |         H

Resources:
Include Chaplex.h, SparkFun_LED_8x7.h
The Chaplex library can be found at: 
http://playground.arduino.cc/Code/Chaplex

Development environment specifics:
Written in Arduino 1.6.7
Tested with SparkFun RedBoard and BadgerStick (Interactive Badge)

This code is released under the [MIT License](http://opensource.org/licenses/MIT).

Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.
****************************************************************/

#include <SparkFun_LED_8x7.h>
#include <Chaplex.h>

// Global variables
byte led_pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pins for LEDs
int x;
int y;
int state;

void setup() {
  
  // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
  
  // Seed our random number generator using the "random"
  // voltage on pin A0
  randomSeed(analogRead(0));
}

void loop() {
  
  // Choose a random number between 0 and 7 for x coordinate
  x = random(0, 8);
  
  // Choose a random number between 0 and 6 for y coordinate
  y = random(0, 7);
  
  // Flip a coin for the state of the LED
  state = random(0, 2);
  
  // Write to the LED display and wait before doing it again
  Plex.pixel(x, y, state);
  Plex.display();
  delay(10);
}