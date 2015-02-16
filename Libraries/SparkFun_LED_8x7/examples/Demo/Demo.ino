/****************************************************************
Demo.ino
LED Array 8x7 Charlieplex
Shawn Hymel @ SparkFun Electronics
February 10, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Gives a demo of all the functions of the LED array. Once
uploaded, click Tools -> Serial Monitor to see debugging
information.

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
byte i;
byte x;
byte y;
byte radius;
const byte sparkfun_logo[] = { 0,0,0,0,1,0,0,0,
                               0,0,0,0,1,0,1,0,
                               0,0,1,0,1,1,1,0,
                               0,0,1,1,1,1,1,0,
                               0,0,1,1,1,1,0,0,
                               0,0,1,1,0,0,0,0,
                               0,0,1,0,0,0,0,0 };

// Setup code - this runs once
void setup() {
  
  // Initialize the serial port
  Serial.begin(9600);
  Serial.println("-----------------------");
  Serial.println("SparkFun LED 8x7 - Demo");
  Serial.println("-----------------------");
  
  // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
  
  // Seed our random number generator with an analog voltage read
  randomSeed(analogRead(0));
}

// Loop code - this runs for infinity
void loop() {

  // Show a bitmap
  Serial.println("Draw a bitmap");
  Plex.clear();
  Plex.drawBitmap(sparkfun_logo);
  Plex.display();
  delay(2000);
  
  // Scroll some text
  Serial.println("Scroll some text");
  Plex.scrollText("Badges?", 1);
  delay(6000);
  
  // Explosions!
  Serial.println("Display an animation");
  for ( i = 0; i < 15; i++ ) {
    x = random(0, 8);
    y = random(0, 7);
    for ( radius = 0; radius < 12; radius++ ) {
      Plex.clear();
      Plex.circle(x, y, radius);
      Plex.circle(x, y, radius + 1);
      Plex.display();
      delay(30);
    }
  }
}