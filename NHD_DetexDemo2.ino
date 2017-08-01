#include <Arduino.h>
#include <U8g2lib.h>

/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

*/

// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

bool f = false;

U8G2_ST7565_NHD_C12864_F_8080 u8g2(U8G2_R0, 8, 9, 10, 11, 4, 5, 6, 7, A0/*WR*/, A1/*CS*/, A2/*A0*/, A3 /*RESET*/); // Connect RD to 3V3

void setup(void) {
  pinMode(2, INPUT_PULLUP);
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFontMode(1);  /* activate transparent font mode */
  u8g2.setDrawColor(2); /* color 1 for the box */
  if (!digitalRead(2)) {
    if (f) u8g2.drawBox(0, 11, 117, 40);
    f = !f;
  } else {
    u8g2.drawBox(0, 11, 117, 40);
  }
  u8g2.setFont(u8g2_font_mercutio_basic_nbp_tf);    // choose a suitable font
  u8g2.drawStr(69, 10, "RUNTIME-->");	// write something to the internal memory
  u8g2.drawStr(2, 24, "DETEX DELAYED EGRESS");
  u8g2.drawStr(4, 37, "CUSTOMER SERVICE:");
  u8g2.drawStr(6, 50, "(800) 729-3839");
  u8g2.drawStr(50, 62, "PROGAMMING-->");
  u8g2.sendBuffer();					// transfer internal memory to the display
  if(f) delay(1500);
  else delay(1000);
}

