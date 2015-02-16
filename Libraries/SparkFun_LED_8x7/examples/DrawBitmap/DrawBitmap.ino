/****************************************************************
DrawBitmap.ino
LED Array 8x7 Charlieplex
Shawn Hymel @ SparkFun Electronics
February 9, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Draws bitmaps on the LEDs.

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
byte led_pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pins for LEDs

const byte bitmap_1[] = { 0,0,0,0,0,0,0,0,
                          0,0,1,0,0,1,0,0,
                          0,1,0,0,1,0,0,0,
                          0,0,1,0,0,1,0,0,
                          0,0,0,0,0,0,0,0,
                          0,0,1,1,1,1,0,0,
                          0,1,0,0,0,0,1,0 };
                          
const byte bitmap_2[] = { 0,0,0,0,0,0,0,0,
                          0,0,1,0,0,1,0,0,
                          0,0,0,1,0,0,1,0,
                          0,0,1,0,0,1,0,0,
                          0,0,0,0,0,0,0,0,
                          0,0,1,1,1,1,0,0,
                          0,1,0,0,0,0,1,0 };
                          
const byte bitmap_3[] = { 0,0,0,0,0,0,0,0,
                          0,0,1,0,0,1,0,0,
                          0,0,1,0,0,1,0,0,
                          0,0,1,0,0,1,0,0,
                          0,0,0,0,0,0,0,0,
                          0,1,0,0,0,0,1,0,
                          0,0,1,1,1,1,0,0 };
                          
const byte sparkfun_logo[] = { 0,0,0,0,1,0,0,0,
                               0,0,0,0,1,0,1,0,
                               0,0,1,0,1,1,1,0,
                               0,0,1,1,1,1,1,0,
                               0,0,1,1,1,1,0,0,
                               0,0,1,1,0,0,0,0,
                               0,0,1,0,0,0,0,0 };
                    
void setup() {
  
  // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
}

void loop() {
  
  // Draw bitmaps in a sequence
  Plex.drawBitmap(bitmap_1);
  Plex.display();
  delay(1000);
  
  Plex.drawBitmap(bitmap_2);
  Plex.display();
  delay(1000);
  
  Plex.drawBitmap(bitmap_3);
  Plex.display();
  delay(2000);
  
  Plex.drawBitmap(sparkfun_logo);
  Plex.display();
  delay(2000);
}