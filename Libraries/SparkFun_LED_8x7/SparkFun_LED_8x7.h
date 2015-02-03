/**
 * @file    SparkFun_LED_8x7.h
 * @brief   Library for the SparkFun 8x7 Charlieplex LED Array
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright	This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This library controls the 8x7 Charlieplex LED array.
 */
 
#ifndef SparkFun_LED_8X7_H
#define SparkFun_LED_8X7_H

#include <Arduino.h>

#include "Chaplex.h"
#include "LED_Font_1.h"

/* Debug */
#define LED_8X7_DEBUG   0

/* Constants */
#define CHAPLEX_PINS    8       // Number of pins
#define TIMER2_TCNT     248     // Refresh: (256-248)*(1024)/(4 MHz) = 2.05 ms
#define CHAR_OFFSET     0x41    // Starting place for ASCII characters
#define CHAR_SPACE      2       // Number of blank columns between characters
#define END_SPACE       6       // Number of blank columns after textattr

/* LED Array class */
class SparkFun_LED_8X7 {
public:
    
    /**
     * @brief Constructor - Instantiates LED array object
     */
    SparkFun_LED_8X7();
    
    /**
     * @brief Destructor
     */
    ~SparkFun_LED_8X7();
    
    /**
     * @brief Configures the pins on the Charlieplex array.
     *
     * You must call this function before performing any other actions on the
     * LED array.
     *
     * @param[in] pins Array of pin numbers. Must be 8 bytes long.
     * @return True if array configured. False on error.
     */
    bool init(/*byte pins[8]*/);

private:

};

#endif // SparkFun_LED_8X7_H