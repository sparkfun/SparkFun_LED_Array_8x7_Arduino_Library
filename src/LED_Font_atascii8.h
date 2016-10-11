/**
 * @file    LED_Font_atascii8.h
 * @brief   ATASCII font for the SparkFun 8x7 Charlieplex LED Array
 * @author  Jeff Piepmeier (jeffpiepmeier.blogspot.com)
 *
 * @copyright	This code is public domain.
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

/*JP - 
  each byte is a column, LSB is top of column
  ATASCII is row oriented (because ANTIC feeds GTIA to write rows of TV screen?)
  ATASCII is mostly 6 columns wide https://damieng.com/blog/2011/02/20/typography-in-8-bits-system-fonts
  https://archive.org/details/ataribooks-de-re-atari - 6 x 6 bitmap
  http://www.atariarchives.org/mapping/appendix10.php ASCII 20 starts at location 0 in Atari ROM
  
  
*/
static const unsigned char c_sp[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};
static const unsigned char c_ex[] PROGMEM = {	8	,	0	,	0	,	0	,	94	,	94	,	0	,	0	,	0	};
static const unsigned char c_qt[] PROGMEM = {	8	,	0	,	14	,	14	,	0	,	0	,	14	,	14	,	0	};
static const unsigned char c_ha[] PROGMEM = {	8	,	36	,	126	,	126	,	36	,	36	,	126	,	126	,	36	};
static const unsigned char c_dl[] PROGMEM = {	8	,	0	,	36	,	46	,	107	,	107	,	58	,	18	,	0	};
static const unsigned char c_pc[] PROGMEM = {	8	,	0	,	102	,	54	,	24	,	12	,	102	,	98	,	0	};
static const unsigned char c_am[] PROGMEM = {	8	,	0	,	48	,	122	,	79	,	93	,	55	,	114	,	80	};
static const unsigned char c_ap[] PROGMEM = {	8	,	0	,	0	,	0	,	14	,	14	,	0	,	0	,	0	};
static const unsigned char c_op[] PROGMEM = {	8	,	0	,	0	,	0	,	60	,	126	,	102	,	66	,	0	};
static const unsigned char c_cp[] PROGMEM = {	8	,	0	,	66	,	102	,	126	,	60	,	0	,	0	,	0	};
static const unsigned char c_as[] PROGMEM = {	8	,	0	,	42	,	62	,	28	,	28	,	62	,	42	,	8	};
static const unsigned char c_pl[] PROGMEM = {	8	,	0	,	8	,	8	,	62	,	62	,	8	,	8	,	0	};
static const unsigned char c_cm[] PROGMEM = {	8	,	0	,	0	,	64	,	112	,	48	,	0	,	0	,	0	};
static const unsigned char c_da[] PROGMEM = {	8	,	0	,	8	,	8	,	8	,	8	,	8	,	8	,	0	};
static const unsigned char c_pr[] PROGMEM = {	8	,	0	,	0	,	0	,	96	,	96	,	0	,	0	,	0	};
static const unsigned char c_fs[] PROGMEM = {	8	,	0	,	96	,	48	,	24	,	12	,	6	,	2	,	0	};
static const unsigned char c_0[] PROGMEM =  {	8	,	0	,	60	,	126	,	82	,	74	,	126	,	60	,	0	};
static const unsigned char c_1[] PROGMEM =  {	8	,	0	,	64	,	68	,	126	,	126	,	64	,	64	,	0	};
static const unsigned char c_2[] PROGMEM =  {	8	,	0	,	68	,	102	,	114	,	90	,	78	,	68	,	0	};
static const unsigned char c_3[] PROGMEM =  {	8	,	0	,	34	,	98	,	74	,	94	,	118	,	34	,	0	};
static const unsigned char c_4[] PROGMEM =  {	8	,	0	,	48	,	56	,	44	,	126	,	126	,	32	,	0	};
static const unsigned char c_5[] PROGMEM =  {	8	,	0	,	46	,	110	,	74	,	74	,	122	,	50	,	0	};
static const unsigned char c_6[] PROGMEM =  {	8	,	0	,	60	,	126	,	74	,	74	,	122	,	48	,	0	};
static const unsigned char c_7[] PROGMEM =  {	8	,	0	,	2	,	98	,	114	,	26	,	14	,	6	,	0	};
static const unsigned char c_8[] PROGMEM =  {	8	,	0	,	52	,	126	,	74	,	74	,	126	,	52	,	0	};
static const unsigned char c_9[] PROGMEM =  {	8	,	0	,	4	,	78	,	74	,	106	,	62	,	28	,	0	};
static const unsigned char c_co[] PROGMEM = {	8	,	0	,	0	,	0	,	108	,	108	,	0	,	0	,	0	};
static const unsigned char c_sc[] PROGMEM = {	8	,	0	,	0	,	64	,	118	,	54	,	0	,	0	,	0	};
static const unsigned char c_lt[] PROGMEM = {	8	,	0	,	0	,	8	,	28	,	54	,	99	,	65	,	0	};
static const unsigned char c_eq[] PROGMEM = {	8	,	0	,	36	,	36	,	36	,	36	,	36	,	36	,	0	};
static const unsigned char c_gt[] PROGMEM = {	8	,	0	,	65	,	99	,	54	,	28	,	8	,	0	,	0	};
static const unsigned char c_qm[] PROGMEM = {	8	,	0	,	4	,	6	,	82	,	90	,	14	,	4	,	0	};
static const unsigned char c_at[] PROGMEM = {	8	,	0	,	60	,	126	,	66	,	90	,	94	,	92	,	0	};
static const unsigned char c_A[] PROGMEM =  {	8	,	0	,	120	,	124	,	38	,	38	,	124	,	120	,	0	};
static const unsigned char c_B[] PROGMEM =  {	8	,	0	,	126	,	126	,	74	,	74	,	126	,	52	,	0	};
static const unsigned char c_C[] PROGMEM =  {	8	,	0	,	60	,	126	,	66	,	66	,	102	,	36	,	0	};
static const unsigned char c_D[] PROGMEM =  {	8	,	0	,	126	,	126	,	66	,	102	,	60	,	24	,	0	};
static const unsigned char c_E[] PROGMEM =  {	8	,	0	,	126	,	126	,	74	,	74	,	74	,	66	,	0	};
static const unsigned char c_F[] PROGMEM =  {	8	,	0	,	126	,	126	,	10	,	10	,	10	,	2	,	0	};
static const unsigned char c_G[] PROGMEM =  {	8	,	0	,	60	,	126	,	66	,	82	,	114	,	114	,	0	};
static const unsigned char c_H[] PROGMEM =  {	8	,	0	,	126	,	126	,	8	,	8	,	126	,	126	,	0	};
static const unsigned char c_I[] PROGMEM =  {	8	,	0	,	66	,	66	,	126	,	126	,	66	,	66	,	0	};
static const unsigned char c_J[] PROGMEM =  {	8	,	0	,	32	,	96	,	64	,	64	,	126	,	62	,	0	};
static const unsigned char c_K[] PROGMEM =  {	8	,	0	,	126	,	126	,	24	,	60	,	102	,	66	,	0	};
static const unsigned char c_L[] PROGMEM =  {	8	,	0	,	126	,	126	,	64	,	64	,	64	,	64	,	0	};
static const unsigned char c_M[] PROGMEM =  {	8	,	0	,	126	,	126	,	12	,	24	,	12	,	126	,	126	};
static const unsigned char c_N[] PROGMEM =  {	8	,	0	,	126	,	126	,	28	,	56	,	126	,	126	,	0	};
static const unsigned char c_O[] PROGMEM =  {	8	,	0	,	60	,	126	,	66	,	66	,	126	,	60	,	0	};
static const unsigned char c_P[] PROGMEM =  {	8	,	0	,	126	,	126	,	18	,	18	,	30	,	12	,	0	};
static const unsigned char c_Q[] PROGMEM =  {	8	,	0	,	60	,	126	,	66	,	34	,	126	,	92	,	0	};
static const unsigned char c_R[] PROGMEM =  {	8	,	0	,	126	,	126	,	18	,	50	,	126	,	76	,	0	};
static const unsigned char c_S[] PROGMEM =  {	8	,	0	,	4	,	78	,	74	,	74	,	122	,	48	,	0	};
static const unsigned char c_T[] PROGMEM =  {	8	,	0	,	2	,	2	,	126	,	126	,	2	,	2	,	0	};
static const unsigned char c_U[] PROGMEM =  {	8	,	0	,	126	,	126	,	64	,	64	,	126	,	126	,	0	};
static const unsigned char c_V[] PROGMEM =  {	8	,	0	,	30	,	62	,	96	,	96	,	62	,	30	,	0	};
static const unsigned char c_W[] PROGMEM =  {	8	,	0	,	126	,	126	,	48	,	24	,	48	,	126	,	126	};
static const unsigned char c_X[] PROGMEM =  {	8	,	0	,	102	,	126	,	24	,	24	,	126	,	102	,	0	};
static const unsigned char c_Y[] PROGMEM =  {	8	,	0	,	6	,	14	,	120	,	120	,	14	,	6	,	0	};
static const unsigned char c_Z[] PROGMEM =  {	8	,	0	,	98	,	114	,	90	,	78	,	70	,	66	,	0	};
static const unsigned char c_ob[] PROGMEM = {	8	,	0	,	0	,	0	,	126	,	126	,	66	,	66	,	0	};
static const unsigned char c_bs[] PROGMEM = {	8	,	0	,	6	,	12	,	24	,	48	,	96	,	64	,	0	};
static const unsigned char c_cb[] PROGMEM = {	8	,	0	,	66	,	66	,	126	,	126	,	0	,	0	,	0	};
static const unsigned char c_ct[] PROGMEM = {	8	,	0	,	16	,	24	,	12	,	6	,	12	,	24	,	16	};
static const unsigned char c_us[] PROGMEM = {	8	,	0	,	64	,	64	,	64	,	64	,	64	,	64	,	64	};
static const unsigned char c_ga[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};
static const unsigned char c_a[] PROGMEM =  {	8	,	0	,	32	,	116	,	84	,	84	,	124	,	120	,	0	};
static const unsigned char c_b[] PROGMEM =  {	8	,	0	,	126	,	126	,	72	,	72	,	120	,	48	,	0	};
static const unsigned char c_c[] PROGMEM =  {	8	,	0	,	56	,	124	,	68	,	68	,	68	,	0	,	0	};
static const unsigned char c_d[] PROGMEM =  {	8	,	0	,	48	,	120	,	72	,	72	,	126	,	126	,	0	};
static const unsigned char c_e[] PROGMEM =  {	8	,	0	,	56	,	124	,	84	,	84	,	92	,	24	,	0	};
static const unsigned char c_f[] PROGMEM =  {	8	,	0	,	0	,	8	,	124	,	126	,	10	,	10	,	0	};
static const unsigned char c_g[] PROGMEM =  {	8	,	0	,	76	,	94	,	82	,	82	,	126	,	62	,	0	};
static const unsigned char c_h[] PROGMEM =  {	8	,	0	,	126	,	126	,	8	,	8	,	120	,	112	,	0	};
static const unsigned char c_i[] PROGMEM =  {	8	,	0	,	0	,	72	,	122	,	122	,	64	,	0	,	0	};
static const unsigned char c_j[] PROGMEM =  {	8	,	0	,	0	,	64	,	64	,	64	,	125	,	61	,	0	};
static const unsigned char c_k[] PROGMEM =  {	8	,	0	,	126	,	126	,	16	,	56	,	104	,	64	,	0	};
static const unsigned char c_l[] PROGMEM =  {	8	,	0	,	0	,	66	,	126	,	126	,	64	,	0	,	0	};
static const unsigned char c_m[] PROGMEM =  {	8	,	0	,	124	,	124	,	24	,	56	,	28	,	124	,	120	};
static const unsigned char c_n[] PROGMEM =  {	8	,	0	,	124	,	124	,	4	,	4	,	124	,	120	,	0	};
static const unsigned char c_o[] PROGMEM =  {	8	,	0	,	56	,	124	,	68	,	68	,	124	,	56	,	0	};
static const unsigned char c_p[] PROGMEM =  {	8	,	0	,	126	,	126	,	18	,	18	,	30	,	12	,	0	};
static const unsigned char c_q[] PROGMEM =  {	8	,	0	,	24	,	60	,	36	,	36	,	124	,	124	,	0	};
static const unsigned char c_r[] PROGMEM =  {	8	,	0	,	124	,	124	,	4	,	4	,	12	,	8	,	0	};
static const unsigned char c_s[] PROGMEM =  {	8	,	0	,	72	,	92	,	84	,	84	,	116	,	36	,	0	};
static const unsigned char c_t[] PROGMEM =  {	8	,	0	,	4	,	4	,	62	,	126	,	68	,	68	,	0	};
static const unsigned char c_u[] PROGMEM =  {	8	,	0	,	60	,	124	,	64	,	64	,	124	,	124	,	0	};
static const unsigned char c_v[] PROGMEM =  {	8	,	0	,	28	,	60	,	96	,	96	,	60	,	28	,	0	};
static const unsigned char c_w[] PROGMEM =  {	8	,	0	,	28	,	124	,	112	,	56	,	112	,	124	,	28	};
static const unsigned char c_x[] PROGMEM =  {	8	,	0	,	68	,	108	,	56	,	56	,	108	,	68	,	0	};
static const unsigned char c_y[] PROGMEM =  {	8	,	0	,	78	,	94	,	80	,	112	,	62	,	30	,	0	};
static const unsigned char c_z[] PROGMEM =  {	8	,	0	,	68	,	100	,	116	,	92	,	76	,	68	,	0	};
static const unsigned char c_oc[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};
static const unsigned char c_vb[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};
static const unsigned char c_cc[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};
static const unsigned char c_tl[] PROGMEM = {	8	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	};


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