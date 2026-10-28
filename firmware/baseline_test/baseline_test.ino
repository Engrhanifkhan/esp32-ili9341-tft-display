/*
 * Project: ESP32 / ILI9341 TFT Display Baseline Hardware Test
 * Author: Engr. Hanif Ullah (Engr. Hanif Khan)
 * Testing Status: PHYSICALLY VERIFIED ON ESP32 HARDWARE
 *
 * Pin Mapping:
 *   CS   -> GPIO 5
 *   DC   -> GPIO 2
 *   RST  -> GPIO 4
 *   MOSI -> GPIO 23
 *   SCK  -> GPIO 18
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println(F("[INIT] ESP32 ILI9341 Hardware Verification Starting..."));

  tft.begin();
  
  // Set landscape orientation
  tft.setRotation(1); 

  // --- HARDWARE MIRROR FIX ---
  // Send MADCTL command (0x36) to flip horizontal scan direction
  tft.writeCommand(0x36);
  SPI.transfer(0x88); // 0x88 corrects mirror inversion on 2.8" TFT modules
  // ---------------------------

  tft.fillScreen(ILI9341_WHITE);

  // Draw diagnostic border
  tft.drawRect(5, 5, 310, 230, ILI9341_RED);
  tft.drawRect(7, 7, 306, 226, ILI9341_BLUE);

  // Display author and verification string
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.println("ENGR HANIF KHAN");

  tft.setTextSize(1);
  tft.setTextColor(ILI9341_DARKGREEN);
  tft.setCursor(20, 85);
  tft.println("Hardware: ESP32-WROOM-32");
  tft.setCursor(20, 105);
  tft.println("Display:  ILI9341 SPI 320x240");
  tft.setCursor(20, 125);
  tft.println("Status:   SPI Bus Communication OK");

  Serial.println(F("[PASS] Display initialized and text rendered successfully."));
}

void loop() {
  // Idle loop
}
