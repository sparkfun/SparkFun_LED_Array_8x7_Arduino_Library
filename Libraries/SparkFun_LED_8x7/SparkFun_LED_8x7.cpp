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
 */
 
#include <Arduino.h>

#include "SparkFun_LED_8x7.h"

/* We need to create an object here so that the ISR knows what to talk to */
SparkFun_LED_8x7 plex;

SparkFun_LED_8x7::SparkFun_LED_8x7()
{
    /* Initialize members */
    scrolling_ = 0;
    shift_count_ = 0;
    scroll_index_ = 0;
    scroll_len_ = 0;

}

SparkFun_LED_8x7::~SparkFun_LED_8x7()
{

}

bool SparkFun_LED_8x7::init(byte pins[NUM_CHAPLEX_PINS])
{

    /* Initialize members (again) */
    scrolling_ = 0;
    shift_count_ = 0;
    scroll_index_ = 0;
    scroll_len_ = 0;

    /* Print out the pins we are using */
#if LED_8X7_DEBUG
    Serial.print("Using pins: ");
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
    for ( byte i = 0; i < 56; i++ ) {
        frame_buffer_[i] = 0;
    }
    display();
    
    return true;
}

void SparkFun_LED_8x7::scrollText(char *in_string)
{
    int i;
    int j;
    int char_ind;
    uint8_t text_len;
    uint8_t dict_size;
    uint8_t char_size;

    /* If we are scrolling, stop and delete our string buffer */
    if ( scrolling_ ) {
        stopScrolling();
    }
    
    /* ***TODO: LIMIT SIZE OF STRING*** */
    /* Calculate characters in the string */
    text_len = strlen(in_string);
#if LED_8X7_DEBUG
    Serial.print("String length: ");
    Serial.println(text_len, DEC);
#endif

    /* Calculate size of buffer */
    scroll_len_ = 0;
    dict_size = sizeof(char_table) / sizeof(char_table[0]);
#if LED_8X7_DEBUG
    Serial.print("Dictionary size: ");
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
        Serial.print("Char ind: ");
        Serial.println(char_ind);
        /***WTF?!?!!?! Not indexing properly***/
        Serial.println(pgm_read_byte(char_table[char_ind]), DEC);
        scroll_len_ += CHAR_SPACE;
    }
    scroll_len_ += END_SPACE;
#if LED_8X7_DEBUG
    Serial.print("Scroll buffer size: ");
    Serial.println(scroll_len_, DEC);
#endif
    
}

void SparkFun_LED_8x7::stopScrolling()
{
    scrolling_ = 0;
    if ( scroll_buf_ != NULL ) {
        scroll_buf_ = NULL;
    }
}

void SparkFun_LED_8x7::display()
{
    for ( byte i = 0; i < 56; i++ ) {
        chaplex_->ledWrite(g_leds[i], frame_buffer_[i]);
    }
    
#if LED_8X7_DEBUG
    Serial.println("Updating display");
#endif
}

void SparkFun_LED_8x7::isr()
{
    byte i;
    byte bit_to_shift;

    /* Disable Timer2 interrupts */
    TIMSK2 &= ~(1 << TOIE2);

    /* Shift one column */
    if ( scrolling_ ) {
        shift_count_++;
        if ( shift_count_ >= shift_delay_ ) {
            shift_delay_ = 0;
            
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
            
            scroll_index_ = 0;
        }
    }

    /* Display a row and reset counter */
    chaplex_->outRow();            // Output for 1 LED row
    TCNT2 = timer2_count_;         // Load counter for next interrupt
    TIMSK2 |= (1 << TOIE2);        // Enable timer overflow interrupt
}

ISR(TIMER2_OVF_vect) {
    plex.isr();
}