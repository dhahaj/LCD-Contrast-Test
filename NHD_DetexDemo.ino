/*

  PrintUTF8.ino

  Use the (Arduino compatible) u8g2 function "print"  to draw a text.

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

*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Frame Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp

U8G2_ST7565_NHD_C12864_F_8080 u8g2(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, A0/*WR*/, A1/*CS*/, A2/*A0*/, A3 /*RESET*/); // Connect RD to 3V3


void setup(void) {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_mercutio_basic_nbp_tf);
  u8g2.setFontDirection(0);
}

void loop(void) {
  u8g2.clearBuffer();
  u8g2.setFontMode(0);
  u8g2.setCursor(69, 10);
  u8g2.print(F("RUNTIME-->"));
  u8g2.setCursor(0, 24);
  u8g2.print(F("DETEX DELAYED EGRESS"));
  u8g2.setCursor(4, 37);
  u8g2.print(F(" CUSTOMER SERVICE:"));
  u8g2.setCursor(6, 50);
  u8g2.print(F(" (800) 729-3839"));
  u8g2.setCursor(50, 62);
  u8g2.setFontMode(1);
  u8g2.print(F("PROGAMMING-->"));		// Chinese "Hello World"
  u8g2.sendBuffer();

  delay(1000);
}

