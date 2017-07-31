/*
  ContrastTest.ino
  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)
*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

  This is a page buffer example.
*/

// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp

U8G2_ST7565_NHD_C12864_1_8080 u8g2(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, A0/*WR*/, A1/*CS*/, A2/*A0*/, A3 /*RESET*/); // Connect RD to 3V3

void testContrast(uint8_t contrast) {
  static char cstr[6];
  static char vstr[4];
  u8g2.setContrast(contrast);
  strcpy( cstr, u8x8_u8toa(contrast, 3));
  u8g2.firstPage();
  do {
    //u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.setFont(u8g2_font_courB24_tn);
    u8g2.drawStr(0, 28, cstr);
    u8g2.drawBox(64, 0, 10, 64);
    u8g2.drawBox(76, 0, 2, 64);
    u8g2.drawBox(80, 0, 1, 64);
    u8g2.drawBox(82, 0, 1, 64);

    u8g2.drawBox(0, 32, 128, 10);
    u8g2.drawBox(0, 44, 128, 2);
    u8g2.drawBox(0, 48, 128, 1);
    u8g2.drawBox(0, 50, 128, 1);
  } while ( u8g2.nextPage() );
}

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  uint8_t i = 255;
  do {
    testContrast(255 - i);
    delay(15);
    i -= 5;
  } while ( i != 0 );
  i = 255;
  delay(100);
  do {
    testContrast(i);
    delay(15);
    i -= 5;
  } while ( i != 0 );
  delay(100);
}

