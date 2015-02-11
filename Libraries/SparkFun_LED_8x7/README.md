SparkFun_LED_8x7
================

Arduino library for the 8x7 LED Charlieplex Array

Version
-------

**v0.9**

Known Issues
------------

* Timer 2 is used to control the LED refresh. You will not be able to use Timer 2 for other functions.

Getting Started
---------------

* Download the Git repository as a ZIP ("Download ZIP" button)
* Unzip
* Copy the entire library directory (SparkFun_LED_8x7) to \<Arduino installation directory\>/libraries
* Open the Arduino program
* Select File -> Examples -> SparkFun_LED_8x7 -> ScrollText
* Plug in your Arduino and LED array with the following connections

| Arduino Pin | LED Array |
|---|---|
| 2 | 2 | 
| 3 | 3 |
| 4 | 4 |
| 5 | 5 |
| 6 | 6 |
| 7 | 7 |
| 8 | 8 |
| 9 | 9 |

* Go to Tools -> Board and select your Arduino board
* Go to Tools -> Serial Port and select the COM port of your Arduino board
* Click "Upload"
* Watch the text scroll across the LEDs

Version History
---------------

**v0.9**

* Implemented scrolling text, bitmaps, and shapes
* Skipped a bunch of versions because I'm lazy

**v0.1**

* Initial commit

License
-------

This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.