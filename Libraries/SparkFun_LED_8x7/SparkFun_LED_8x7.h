/**
 * @file    SparkFun_LED_8x7.h
 * @brief   Library for the SparkFun 8x7 Charlieplex LED Array
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright	This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This library controls the 8x7 Charlieplex LED array. Note that Timer2 is used
 * in this library to control the LED refresh. You will not be able to use it
 * for other uses.
 *
 * Relies on the Chaplex library written by Stefan Götze.
 */
 
#ifndef SparkFun_LED_8x7_H
#define SparkFun_LED_8x7_H

#include <Arduino.h>

#include <Chaplex.h>
#include "LED_Font_1.h"

/* Debug */
#define LED_8X7_DEBUG   0

/* Constants */
#define NUM_CHAPLEX_PINS    8       // Number of pins   
#define TIMER2_TCNT         248     // Refresh: (256-248)*(1024)/(4 MHz)=2.05 ms
#define DEFAULT_SHIFT_DELAY 50      // Number of ticks to wait before scrolling
#define MAX_CHARS           100     // Maximum characters to scroll
#define CHAR_OFFSET         0x41    // Starting place for ASCII characters
#define CHAR_SPACE          2       // Number of blank columns between chars
#define END_SPACE           6       // Number of blank columns after text
#define COL_SIZE            7       // Number of LEDs in a single column
#define ROW_SIZE            8       // Number of LEDs in a single row
#define NUM_LEDS            COL_SIZE * ROW_SIZE
#define ALL_BUT_LAST_COL    NUM_LEDS - COL_SIZE

/* Global variables */
static charlieLed g_leds[56] = {{0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7},   
                                {1,0}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7},
                                {2,0}, {2,1}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7},
                                {3,0}, {3,1}, {3,2}, {3,4}, {3,5}, {3,6}, {3,7},
                                {4,0}, {4,1}, {4,2}, {4,3}, {4,5}, {4,6}, {4,7},
                                {5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,6}, {5,7},
                                {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,7},
                                {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}
                                };
 
/**
 * @brief Global interrupt service routine for Timer 2
 *
 * We declare Timer 2 ISR here to allow us to make calls to functions in the
 * SparkFun_LED_8x7 class. To do this, we instantiate a SparkFun_LED_8x7 object
 * (globally) in the .cpp file. This is then used in the main sketch.
 **/
ISR(TIMER2_OVF_vect);

/* LED Array class */
class SparkFun_LED_8x7 {
    
    /* The ISR is our friend! It can call our functions. */
    friend void TIMER2_OVF_vect();
    
public:
    
    /**
     * @brief Constructor - Instantiates LED array object
     */
    SparkFun_LED_8x7();
    
    /**
     * @brief Destructor
     */
    ~SparkFun_LED_8x7();
    
    /**
     * @brief Configures the pins on the Charlieplex array.
     *
     * You must call this function before performing any other actions on the
     * LED array.
     *
     * @param[in] pins Array of pin numbers. Must be 8 bytes long.
     * @return True if array configured. False on error.
     */
    bool init(byte pins[NUM_CHAPLEX_PINS]);
    
    /**
     * @brief Clears the Charlieplex array.
     */
    void clear();
    
    /**
     * @brief Sets text to scroll across the LED array
     *
     * @param[in] in_string Text to scroll
     */
    void scrollText(char *in_string);
    
    /**
     * @brief Stops scrolling text and deletes scroll buffer
     */
    void stopScrolling();
    
    /**
     * @brief Writes the frame buffer to the LED buffer.
     */
    void display();

private:

    /* Members */
    Chaplex *chaplex_;      /// Chaplex object for controlling the LEDs
    byte frame_buffer_[56]; /// Storing the state of each LED to be written
    byte timer2_count_;     /// Stores the next start point for Timer2
    byte *scroll_buf_;      /// Buffer of text graphics to scroll
    byte scrolling_;        /// Boolean to indicate if we are scrolling text
    unsigned int shift_count_;  /// Count number of ticks before shifting text
    unsigned int shift_delay_;  /// Number of ticks to wait before shifting text
    unsigned int scroll_index_; /// Index of where to scroll text
    unsigned int scroll_len_;   /// Number of bytes in scroll_buf_
    
    inline void isr();

};

extern SparkFun_LED_8x7 plex;

#endif // SparkFun_LED_8x7_H