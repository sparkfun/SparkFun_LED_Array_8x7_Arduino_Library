/****************************************************************
ScrollText.ino
LED Array 8x7 Charlieplex
Shawn Hymel @ SparkFun Electronics
February 3, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Scrolls text across the LED array for 10 seconds.

Hardware Connections:

IMPORTANT:  The Charlieplex LED board is designed for 2.0 - 3.3V!
            Higher voltages can damage the LEDs.

 Arduino Pin | Charlieplex Board
 ------------|------------------
      2      |         2
      3      |         3
      4      |         4
      5      |         5
      6      |         6
      7      |         7
      8      |         8
      9      |         9

Resources:
Include Chaplex.h, SparkFun_LED_8x7.h
The Chaplex library can be found at: 
http://playground.arduino.cc/Code/Chaplex

Development environment specifics:
Written in Arduino 1.0.6
Tested with SparkFun BadgerStick (Interactive Badge)

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, please
buy us a round!

Distributed as-is; no warranty is given.
****************************************************************/

#include <SparkFun_LED_8x7.h>
#include <Chaplex.h>

// Global variables
static byte led_pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pins for LEDs

void setup() {

  // Initialize LED array
  Plex.init(led_pins);
  
  // Clear display
  Plex.clear();
  Plex.display();
}

void loop() {
  
  // Scroll text 2 times (blocking)
  Plex.scrollText("Hello. :)", 2, true);
  
  // Scroll text until we stop it
  Plex.scrollText("Let's scroll!");
  delay(10000);
  Plex.stopScrolling();
  delay(1000);
}