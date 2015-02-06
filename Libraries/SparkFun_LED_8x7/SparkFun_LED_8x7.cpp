/**
 * @file    SparkFun_LED_8x7.cpp
 * @brief   Library for the SparkFun 8x7 Charlieplex LED Array
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright	This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This library controls the 8x7 Charlieplex LED array.
 */
 
#include <Arduino.h>

#include "SparkFun_LED_8x7.h"

SparkFun_LED_8x7::SparkFun_LED_8x7()
{

}

SparkFun_LED_8x7::~SparkFun_LED_8x7()
{

}

bool SparkFun_LED_8x7::init(byte pins[CHAPLEX_PINS])
{
    return true;
}