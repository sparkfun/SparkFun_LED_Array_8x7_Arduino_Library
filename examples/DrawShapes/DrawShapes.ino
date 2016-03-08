/****************************************************************
DrawShapes.ino
LED Array 8x7 Charlieplex
Shawn Hymel @ SparkFun Electronics
February 9, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Draws lines, rectangles, and circles on the LEDs.

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
byte i;

void setup() {
  
  // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
}

void loop() {
  
  // Draw a dot (x, y)
  Plex.clear();
  Plex.pixel(1, 2);
  Plex.display();
  delay(1000);
  
  // Draw a line (x0, y0, y1, y1)
  Plex.clear();
  Plex.line(1, 2, 5, 5);
  Plex.display();
  delay(1000);
  
  // Draw a rectangle (x, y, width, height)
  Plex.clear();
  Plex.rect(1, 2, 5, 4);
  Plex.display();
  delay(1000);
  
  // Draw a filled rectangle (x, y, width, height)
  Plex.clear();
  Plex.rectFill(1, 2, 5, 4);
  Plex.display();
  delay(1000);
  
  // Draw a circle (x, y, radius)
  Plex.clear();
  Plex.circle(3, 3, 3);
  Plex.display();
  delay(1000);
  
  // Draw a filled circle (x, y, radius)
  Plex.clear();
  Plex.circleFill(3, 3, 3);
  Plex.display();
  delay(1000);
}