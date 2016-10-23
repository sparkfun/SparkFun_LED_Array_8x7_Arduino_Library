/**
 * @file    LED_Font_atascii_variable.h
 * @brief   variable width ATASCII font for the SparkFun 8x7 Charlieplex LED Array
 * @author  Jeff Piepmeier (jeffpiepmeier.blogspot.com)
 *
 * @copyright This code is public domain.
 *
 * This font file supports the 8x7 Charlieplex LED array by defining the LEDs
 * that need to turn off and on for each character.
 * 
 * it is based on the LED_Font_1.h file by Shawn Hymel of Sparkfun
*/
/* BASED ON THIS FILE ...
 * @file    LED_Font_1.h
 * @brief   Font 1 for the SparkFun 8x7 Charlieplex LED Array
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This font file supports the 8x7 Charlieplex LED array by defining the LEDs
 * that need to turn off and on for each character.
 */
 
#ifndef LED_Font_1_H
#define LED_Font_1_H

/* Variable size character widths */
/* Format: { size in bytes of char, byte 1, byte 2, ... } */

/*JP - 
  each byte is a column, LSB is top of column
  ATASCII is row oriented (because ANTIC feeds GTIA to write rows of TV screen?)
  ATASCII is mostly 6 columns wide https://damieng.com/blog/2011/02/20/typography-in-8-bits-system-fonts
  https://archive.org/details/ataribooks-de-re-atari - 6 x 6 bitmap
  http://www.atariarchives.org/mapping/appendix10.php ASCII 20 starts at location 0 in Atari ROM
  
  
*/
static const unsigned char c_sp[] PROGMEM = { 1  };
static const unsigned char c_ex[] PROGMEM = { 2 , 94 , 94 };
static const unsigned char c_qt[] PROGMEM = { 6 , 14 , 14   , 14 , 14 };
static const unsigned char c_ha[] PROGMEM = { 8 , 36 , 126 , 126 , 36 , 36 , 126 , 126 , 36 };
static const unsigned char c_dl[] PROGMEM = { 6 , 36 , 46 , 107 , 107 , 58 , 18 };
static const unsigned char c_pc[] PROGMEM = { 6 , 102 , 54 , 24 , 12 , 102 , 98 };
static const unsigned char c_am[] PROGMEM = { 7 , 48 , 122 , 79 , 93 , 55 , 114 , 80 };
static const unsigned char c_ap[] PROGMEM = { 2 , 14 , 14 };
static const unsigned char c_op[] PROGMEM = { 4 , 60 , 126 , 102 , 66 };
static const unsigned char c_cp[] PROGMEM = { 4 , 66 , 102 , 126 , 60 };
static const unsigned char c_as[] PROGMEM = { 7 , 42 , 62 , 28 , 28 , 62 , 42 , 8 };
static const unsigned char c_pl[] PROGMEM = { 6 , 8 , 8 , 62 , 62 , 8 , 8  };
static const unsigned char c_cm[] PROGMEM = { 3 , 64 , 112 , 48 };
static const unsigned char c_da[] PROGMEM = { 6 , 8 , 8 , 8 , 8 , 8 , 8 };
static const unsigned char c_pr[] PROGMEM = { 2 , 96 , 96 };
static const unsigned char c_fs[] PROGMEM = { 6 , 96 , 48 , 24 , 12 , 6 , 2 };
static const unsigned char c_0[] PROGMEM =  { 6 , 60 , 126 , 82 , 74 , 126 , 60  };
static const unsigned char c_1[] PROGMEM =  { 6  , 64 , 68 , 126 , 126 , 64 , 64  };
static const unsigned char c_2[] PROGMEM =  { 6  , 68 , 102 , 114 , 90 , 78 , 68  };
static const unsigned char c_3[] PROGMEM =  { 6  , 34 , 98 , 74 , 94 , 118 , 34  };
static const unsigned char c_4[] PROGMEM =  { 6  , 48 , 56 , 44 , 126 , 126 , 32  };
static const unsigned char c_5[] PROGMEM =  { 6  , 46 , 110 , 74 , 74 , 122 , 50  };
static const unsigned char c_6[] PROGMEM =  { 6  , 60 , 126 , 74 , 74 , 122 , 48  };
static const unsigned char c_7[] PROGMEM =  { 6  , 2 , 98 , 114 , 26 , 14 , 6  };
static const unsigned char c_8[] PROGMEM =  { 6  , 52 , 126 , 74 , 74 , 126 , 52  };
static const unsigned char c_9[] PROGMEM =  { 6  , 4 , 78 , 74 , 106 , 62 , 28  };
static const unsigned char c_co[] PROGMEM = { 2    , 108 , 108    };
static const unsigned char c_sc[] PROGMEM = { 3   , 64 , 118 , 54    };
static const unsigned char c_lt[] PROGMEM = { 5   , 8 , 28 , 54 , 99 , 65  };
static const unsigned char c_eq[] PROGMEM = { 6  , 36 , 36 , 36 , 36 , 36 , 36  };
static const unsigned char c_gt[] PROGMEM = { 5  , 65 , 99 , 54 , 28 , 8   };
static const unsigned char c_qm[] PROGMEM = { 6  , 4 , 6 , 82 , 90 , 14 , 4  };
static const unsigned char c_at[] PROGMEM = { 6  , 60 , 126 , 66 , 90 , 94 , 92  };
static const unsigned char c_A[] PROGMEM =  { 6  , 120 , 124 , 38 , 38 , 124 , 120  };
static const unsigned char c_B[] PROGMEM =  { 6  , 126 , 126 , 74 , 74 , 126 , 52  };
static const unsigned char c_C[] PROGMEM =  { 6  , 60 , 126 , 66 , 66 , 102 , 36  };
static const unsigned char c_D[] PROGMEM =  { 6  , 126 , 126 , 66 , 102 , 60 , 24  };
static const unsigned char c_E[] PROGMEM =  { 6  , 126 , 126 , 74 , 74 , 74 , 66  };
static const unsigned char c_F[] PROGMEM =  { 6  , 126 , 126 , 10 , 10 , 10 , 2  };
static const unsigned char c_G[] PROGMEM =  { 6  , 60 , 126 , 66 , 82 , 114 , 114  };
static const unsigned char c_H[] PROGMEM =  { 6  , 126 , 126 , 8 , 8 , 126 , 126  };
static const unsigned char c_I[] PROGMEM =  { 6  , 66 , 66 , 126 , 126 , 66 , 66  };
static const unsigned char c_J[] PROGMEM =  { 6  , 32 , 96 , 64 , 64 , 126 , 62  };
static const unsigned char c_K[] PROGMEM =  { 6  , 126 , 126 , 24 , 60 , 102 , 66  };
static const unsigned char c_L[] PROGMEM =  { 6  , 126 , 126 , 64 , 64 , 64 , 64  };
static const unsigned char c_M[] PROGMEM =  { 7  , 126 , 126 , 12 , 24 , 12 , 126 , 126 };
static const unsigned char c_N[] PROGMEM =  { 6  , 126 , 126 , 28 , 56 , 126 , 126  };
static const unsigned char c_O[] PROGMEM =  { 6  , 60 , 126 , 66 , 66 , 126 , 60  };
static const unsigned char c_P[] PROGMEM =  { 6  , 126 , 126 , 18 , 18 , 30 , 12  };
static const unsigned char c_Q[] PROGMEM =  { 6  , 60 , 126 , 66 , 34 , 126 , 92  };
static const unsigned char c_R[] PROGMEM =  { 6  , 126 , 126 , 18 , 50 , 126 , 76  };
static const unsigned char c_S[] PROGMEM =  { 6  , 4 , 78 , 74 , 74 , 122 , 48  };
static const unsigned char c_T[] PROGMEM =  { 6  , 2 , 2 , 126 , 126 , 2 , 2  };
static const unsigned char c_U[] PROGMEM =  { 6  , 126 , 126 , 64 , 64 , 126 , 126  };
static const unsigned char c_V[] PROGMEM =  { 6  , 30 , 62 , 96 , 96 , 62 , 30  };
static const unsigned char c_W[] PROGMEM =  { 7  , 126 , 126 , 48 , 24 , 48 , 126 , 126 };
static const unsigned char c_X[] PROGMEM =  { 6  , 102 , 126 , 24 , 24 , 126 , 102  };
static const unsigned char c_Y[] PROGMEM =  { 6  , 6 , 14 , 120 , 120 , 14 , 6  };
static const unsigned char c_Z[] PROGMEM =  { 6  , 98 , 114 , 90 , 78 , 70 , 66  };
static const unsigned char c_ob[] PROGMEM = { 4    , 126 , 126 , 66 , 66  };
static const unsigned char c_bs[] PROGMEM = { 6  , 6 , 12 , 24 , 48 , 96 , 64  };
static const unsigned char c_cb[] PROGMEM = { 4  , 66 , 66 , 126 , 126    };
static const unsigned char c_ct[] PROGMEM = { 7  , 16 , 24 , 12 , 6 , 12 , 24 , 16 };
static const unsigned char c_us[] PROGMEM = { 7  , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
static const unsigned char c_ga[] PROGMEM = { 8 , 96, 120, 15, 127, 127, 15, 120, 96  };
static const unsigned char c_a[] PROGMEM =  { 6  , 32 , 116 , 84 , 84 , 124 , 120  };
static const unsigned char c_b[] PROGMEM =  { 6  , 126 , 126 , 72 , 72 , 120 , 48  };
static const unsigned char c_c[] PROGMEM =  { 5  , 56 , 124 , 68 , 68 , 68   };
static const unsigned char c_d[] PROGMEM =  { 6  , 48 , 120 , 72 , 72 , 126 , 126  };
static const unsigned char c_e[] PROGMEM =  { 6  , 56 , 124 , 84 , 84 , 92 , 24  };
static const unsigned char c_f[] PROGMEM =  { 5   , 8 , 124 , 126 , 10 , 10  };
static const unsigned char c_g[] PROGMEM =  { 6  , 76 , 94 , 82 , 82 , 126 , 62  };
static const unsigned char c_h[] PROGMEM =  { 6  , 126 , 126 , 8 , 8 , 120 , 112  };
static const unsigned char c_i[] PROGMEM =  { 4   , 72 , 122 , 122 , 64   };
static const unsigned char c_j[] PROGMEM =  { 5   , 64 , 64 , 64 , 125 , 61  };
static const unsigned char c_k[] PROGMEM =  { 6  , 126 , 126 , 16 , 56 , 104 , 64  };
static const unsigned char c_l[] PROGMEM =  { 4   , 66 , 126 , 126 , 64   };
static const unsigned char c_m[] PROGMEM =  { 7  , 124 , 124 , 24 , 56 , 28 , 124 , 120 };
static const unsigned char c_n[] PROGMEM =  { 6  , 124 , 124 , 4 , 4 , 124 , 120  };
static const unsigned char c_o[] PROGMEM =  { 6  , 56 , 124 , 68 , 68 , 124 , 56  };
static const unsigned char c_p[] PROGMEM =  { 6  , 126 , 126 , 18 , 18 , 30 , 12  };
static const unsigned char c_q[] PROGMEM =  { 6  , 24 , 60 , 36 , 36 , 124 , 124  };
static const unsigned char c_r[] PROGMEM =  { 6  , 124 , 124 , 4 , 4 , 12 , 8  };
static const unsigned char c_s[] PROGMEM =  { 6  , 72 , 92 , 84 , 84 , 116 , 36  };
static const unsigned char c_t[] PROGMEM =  { 6  , 4 , 4 , 62 , 126 , 68 , 68  };
static const unsigned char c_u[] PROGMEM =  { 6  , 60 , 124 , 64 , 64 , 124 , 124  };
static const unsigned char c_v[] PROGMEM =  { 6  , 28 , 60 , 96 , 96 , 60 , 28  };
static const unsigned char c_w[] PROGMEM =  { 7  , 28 , 124 , 112 , 56 , 112 , 124 , 28 };
static const unsigned char c_x[] PROGMEM =  { 6  , 68 , 108 , 56 , 56 , 108 , 68  };
static const unsigned char c_y[] PROGMEM =  { 6  , 78 , 94 , 80 , 112 , 62 , 30  };
static const unsigned char c_z[] PROGMEM =  { 6  , 68 , 100 , 116 , 92 , 76 , 68  };
static const unsigned char c_oc[] PROGMEM = { 7 , 96, 120, 15, 127, 127, 15, 120, 96 };
static const unsigned char c_vb[] PROGMEM = { 1 ,0 };
static const unsigned char c_cc[] PROGMEM = { 1, 0 };
static const unsigned char c_tl[] PROGMEM = { 1, 0 };


/* Pointers to characters */
const unsigned char * const char_table[] PROGMEM = { 
    c_sp, c_ex, c_qt, c_ha, c_dl, c_pc, c_am, c_ap, c_op, c_cp, c_as, c_pl, 
    c_cm, c_da, c_pr, c_fs, c_0,  c_1,  c_2,  c_3,  c_4,  c_5,  c_6,  c_7,  
    c_8,  c_9,  c_co, c_sc, c_lt, c_eq, c_gt, c_qm, c_at, c_A,  c_B,  c_C,  
    c_D,  c_E,  c_F,  c_G,  c_H,  c_I,  c_J,  c_K,  c_L,  c_M,  c_N,  c_O, 
    c_P,  c_Q,  c_R,  c_S,  c_T,  c_U,  c_V,  c_W,  c_X,  c_Y,  c_Z,  c_ob,
    c_bs, c_cb, c_ct, c_us, c_ga, c_a,  c_b,  c_c,  c_d,  c_e,  c_f,  c_g,
    c_h,  c_i,  c_j,  c_k,  c_l,  c_m,  c_n,  c_o,  c_p,  c_q,  c_r,  c_s,
    c_t,  c_u,  c_v,  c_w,  c_x,  c_y,  c_z,  c_oc, c_vb, c_cc, c_tl 
};


#endif // LED_Font_atascii