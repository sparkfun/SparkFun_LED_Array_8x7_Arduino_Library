/**
 * @file    SparkFun_LED_8x7.cpp
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
 
#include <Arduino.h>

#include "SparkFun_LED_8x7.h"

/* We need to create a global instance so that the ISR knows what to talk to */
SparkFun_LED_8x7 Plex;

/**
 * @brief Define static member for the location of the LEDs
 */
const charlieLed SparkFun_LED_8x7::charlie_leds_[] = {
                            {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7},   
                            {1,0}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7},
                            {2,0}, {2,1}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7},
                            {3,0}, {3,1}, {3,2}, {3,4}, {3,5}, {3,6}, {3,7},
                            {4,0}, {4,1}, {4,2}, {4,3}, {4,5}, {4,6}, {4,7},
                            {5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,6}, {5,7},
                            {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,7},
                            {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}
                            };

/**
 * @brief Constructor - Instantiates LED array object
 */
SparkFun_LED_8x7::SparkFun_LED_8x7()
{
    /* Initialize members */
    scrolling_ = 0;
    shift_count_ = 0;
    shift_delay_ = DEFAULT_SHIFT_DELAY;
    scroll_index_ = 0;
    scroll_len_ = 0;

}

/**
 * @brief Destructor
 */
SparkFun_LED_8x7::~SparkFun_LED_8x7()
{

}
    
/**
 * @brief Configures the pins on the Charlieplex array.
 *
 * You must call this function before performing any other actions on the
 * LED array.
 *
 * @param[in] pins Array of pin numbers. Must be 8 bytes long.
 * @return True if array configured. False on error.
 */
bool SparkFun_LED_8x7::init(byte pins[NUM_CHAPLEX_PINS])
{
    /* If we are scrolling, stop and delete our string buffer */
    if ( scrolling_ ) {
        stopScrolling();
    }

    /* Initialize members (again) */
    scrolling_ = 0;
    shift_count_ = 0;
    shift_delay_ = DEFAULT_SHIFT_DELAY;
    scroll_index_ = 0;
    scroll_len_ = 0;

    /* Print out the pins we are using */
#if LED_8X7_DEBUG
    Serial.print(F("Using pins: "));
    for ( int i = 0; i < NUM_CHAPLEX_PINS; i++ ) {
        Serial.print(pins[i]);
        Serial.print(" ");
    }
    Serial.println();
#endif

    /* If we alread have a Chaplex object, delete it */
    if ( chaplex_ != NULL ) {
        delete chaplex_;
    }
    
    /* Create a new Chaplex object so we can write stuff to the LEDs */
    chaplex_ = new Chaplex(pins, NUM_CHAPLEX_PINS);

    /* Initialize Timer 2 */
    timer2_count_ = TIMER2_TCNT;            // Load in starting count
    noInterrupts();                         // Disable interrupts
    TCCR2A = 0;                             // Normal operation
    TCCR2B = 0;                             // Clear prescaler
    TCNT2 = timer2_count_;                  // Load counter
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);  // Prescaler = 1024
    TIMSK2 |= (1 << TOIE2);                 // Enable timer overflow interrupt
    interrupts();                           // Enable all interrupts

    /* Clear and load frame buffer */
    clear();
    display();
    
    return true;
}

/**
 * @brief Writes the frame buffer to the LED buffer.
 */
void SparkFun_LED_8x7::display()
{
    for ( byte i = 0; i < NUM_LEDS; i++ ) {
        chaplex_->ledWrite(charlie_leds_[i], frame_buffer_[i]);
    }
}

/**
 * @brief Clears the Charlieplex array.
 */
void SparkFun_LED_8x7::clear()
{
    memset(frame_buffer_, 0, NUM_LEDS);
}

/**
 * @brief Turns a pixel at a given (x, y) on or off
 *
 * Coordinates start (0, 0) from the top-left of the display.
 *
 * @param[in] x X coordinate for the pixel
 * @param[in] y Y coordinate for the pixel
 * @param[in] on 1 for on, 0 for off.
 */
void SparkFun_LED_8x7::pixel(uint8_t x, uint8_t y, uint8_t on /* = 1 */)
{
    /* Check to make sure that we are not accessing outside the array */
    if ( x >= ROW_SIZE || y >= COL_SIZE ) {
        return;
    }
    
    /* Turn the specified LED on or off. Note that we need to switch our X and Y
     * for the user, as X goes down and Y goes across on the actual LED display.
     */
    if ( on ) {
        frame_buffer_[(x * COL_SIZE) + y] = 1;
    } else {
        frame_buffer_[(x * COL_SIZE) + y] = 0;
    }
}

/**
 * @brief Loads an array of LED states (on or off).
 *
 * param[in] bitmap Array of LED states. 0 = off, 1 = on.
 */
void SparkFun_LED_8x7::drawBitmap(byte bitmap[NUM_LEDS])
{
    uint8_t x;
    uint8_t y;
    
    /* Transpose matrix 90 degrees (switch x and y) */
    for ( x = 0; x < COL_SIZE; x++ ) {
        for ( y = 0; y < ROW_SIZE; y++ ) {
            frame_buffer_[(x * COL_SIZE) + y] = 
                (bitmap[(y * ROW_SIZE) + x] ? 1: 0);
            Serial.println(frame_buffer_[(x * COL_SIZE) + y], DEC);
        }
    }
}

/**
 * @brief Sets text to scroll across the LED array indefinitely
 *
 * @param[in] in_string Text to scroll
 */
void SparkFun_LED_8x7::scrollText(char *in_string)
{
    scrollText(in_string, 0);
}

/**
 * @brief Scrolls text a specified number of times
 *
 * @param[in] in_string Text to scroll
 * @param[in] times Number of times to scroll the text
 */
void SparkFun_LED_8x7::scrollText(char *in_string, int times)
{
    int i;
    int j;
    int char_ind;
    int buf_ind;
    uint8_t text_len;
    uint8_t dict_size;
    uint8_t char_size;

    /* If we are scrolling, stop and delete our string buffer */
    if ( scrolling_ ) {
        stopScrolling();
    }
    
    /* Reset our counters */
    shift_count_ = 0;
    scroll_index_ = 0;
    scroll_times_ = times;
    scroll_count_ = 0;
    
    /* Calculate characters in the string */
    text_len = strlen(in_string);
    if ( text_len > MAX_CHARS ) {
        text_len = MAX_CHARS;
    }
#if LED_8X7_DEBUG
    Serial.print(F("String length: "));
    Serial.println(text_len, DEC);
#endif

    /* Calculate size of buffer */
    scroll_len_ = 0;
    dict_size = sizeof(char_table) / sizeof(char_table[0]);
#if LED_8X7_DEBUG
    Serial.print(F("Dictionary size: "));
    Serial.println(dict_size, DEC);
#endif
    for ( i = 0; i < text_len; i++ ) {
        
        /* Find where in the dictionary the character occurs */
        char_ind = in_string[i] - CHAR_OFFSET;
        
        /* If character is not in the dictionary, don't count it */
        if ( char_ind < 0 || char_ind >= dict_size ) {
            continue;
        }

        /* Add the number of columns in the character plus the space after */
        scroll_len_ += pgm_read_byte(char_table[char_ind]);
        scroll_len_ += CHAR_SPACE;
    }
    scroll_len_ += END_SPACE;
#if LED_8X7_DEBUG
    Serial.print(F("Scroll buffer size: "));
    Serial.println(scroll_len_, DEC);
#endif

    /* Create buffer */
    buf_ind = 0;
    scroll_buf_ = (byte*)malloc(scroll_len_ * sizeof(byte));
    for ( i = 0; i < text_len; i++ ) {
        
        /* Find where in the diction the character occurs */
        char_ind = in_string[i] - CHAR_OFFSET;
        
        /* If character is not in the dictionary, skip it */
        if ( char_ind < 0 || char_ind >= dict_size ) {
            continue;
        }
        
        /* For that character, load in the definition (bytes show which LEDs) */
        char_size = pgm_read_byte(char_table[char_ind]);
        for ( j = 1; j < char_size + 1; j++ ) {
            scroll_buf_[buf_ind] = pgm_read_byte(char_table[char_ind] + j);
            buf_ind++;
        }
        
        /* Add in spaces after each char */
        for ( j = 0; j < CHAR_SPACE; j++ ) {
            scroll_buf_[buf_ind] = 0;
            buf_ind++;
        }
    }
    
    /* Add in spaces after text */
    for ( i = 0; i < END_SPACE; i++ ) {
        scroll_buf_[buf_ind] = 0;
        buf_ind++;
    }
    
    /* Print buffer */
#if 0
    for ( i = 0; i < scroll_len_; i++ ) {
        Serial.println(scroll_buf_[i], HEX);
    }
#endif

    /* Start scrolling */
    scrolling_ = 1;
}

/**
 * @brief Stops scrolling text and deletes scroll buffer
 */
void SparkFun_LED_8x7::stopScrolling()
{
    scrolling_ = 0;
    if ( scroll_buf_ != NULL ) {
        free(scroll_buf_);
        scroll_buf_ = NULL;
    }
    clear();
    display();
}

void SparkFun_LED_8x7::isr()
{

    /* Disable Timer2 interrupts */
    TIMSK2 &= ~(1 << TOIE2);

    /* Shift one column */
    if ( scrolling_ ) {
        shift_count_++;
        if ( shift_count_ >= shift_delay_ ) {
            shift_count_ = 0;
            byte i;
            byte bit_to_shift;
            
            /* Shift all but last column */
            for ( i = 0; i < ALL_BUT_LAST_COL; i++ ) {
                frame_buffer_[i] = frame_buffer_[i + COL_SIZE];
            }
            
            /* Shift in new column at the end */
            for ( i = 0; i < COL_SIZE; i++ ) {
                bit_to_shift = (scroll_buf_[scroll_index_] >> i) & 0x01;
                frame_buffer_[ALL_BUT_LAST_COL + i] = bit_to_shift;
            }
            
            /* Send everything in our new buffer to the LED matrix */
            display();
            
            /* Increment buffer index and reset if it reaches the end */
            scroll_index_++;
            if ( scroll_index_ >= scroll_len_ ) {
                scroll_index_ = 0;
                if ( scroll_times_ > 0 ) {
                    scroll_count_++;
                    if ( scroll_count_ >= scroll_times_ ) {
                        stopScrolling();
                    }
                }
            }
        }
    }

    /* Display a row and reset counter */
    chaplex_->outRow();            // Output for 1 LED row
    TCNT2 = timer2_count_;         // Load counter for next interrupt
    TIMSK2 |= (1 << TOIE2);        // Enable timer overflow interrupt
}

/**
 * @brief Global interrupt service routine for Timer 2
 *
 * We define Timer 2 ISR here to allow us to make calls to functions in the
 * SparkFun_LED_8x7 class. To do this, we instantiate a SparkFun_LED_8x7 object
 * (globally) in the .cpp file.
 **/
ISR(TIMER2_OVF_vect) {
    Plex.isr();
}