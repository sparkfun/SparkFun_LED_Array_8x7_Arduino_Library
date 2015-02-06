/**
 * @file    LED_Font_1.h
 * @brief   Font 1 for the SparkFun 8x7 Charlieplex LED Array
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright	This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This font file supports the 8x7 Charlieplex LED array by defining the LEDs
 * that need to turn off and on for each character.
 */
 
#ifndef LED_Font_1_H
#define LED_Font_1_H

/* Variable size character widths */
/* Format: { size in bytes of char, byte 1, byte 2, ... } */
static const char char_A[] PROGMEM = { 4, 0x7E, 0x11, 0x11, 0x7E };
static const char char_B[] PROGMEM = { 4, 0x7F, 0x49, 0x49, 0x36 };
static const char char_C[] PROGMEM = { 4, 0x3E, 0x41, 0x41, 0x22 };
static const char char_D[] PROGMEM = { 4, 0x7F, 0x41, 0x22, 0x1C };
static const char char_E[] PROGMEM = { 4, 0x7F, 0x49, 0x49, 0x41 };
static const char char_F[] PROGMEM = { 4, 0x7F, 0x09, 0x09, 0x01 };
static const char char_G[] PROGMEM = { 4, 0x3E, 0x41, 0x49, 0x7A };
static const char char_H[] PROGMEM = { 4, 0x7F, 0x08, 0x08, 0x7F };
static const char char_I[] PROGMEM = { 3, 0x41, 0x7F, 0x41 };

/* Pointers to characters */
static PGM_P char_table[] PROGMEM = { char_A, char_B, char_C, char_D, char_E, 
                                      char_F, char_G, char_H, char_I, };/*char_J, char_K, char_L, char_M, char_N,
                        char_O, char_P, char_Q, char_R, char_S, char_T, char_U,
                        char_V, char_W, char_X, char_Y, char_Z };*/

#endif // LED_Font_1_H