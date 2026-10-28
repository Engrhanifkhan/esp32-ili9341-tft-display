/*
 * Project: ESP32 / ILI9341 Graphic Telemetry Dashboard
 * Author: Engr. Hanif Ullah (Engr. Hanif Khan)
 *
 * NOTE: REFERENCE IMPLEMENTATION — PHYSICAL HARDWARE TESTING PENDING.
 * This sketch demonstrates multi-gauge layout and non-blocking screen rendering.
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

unsigned long lastUpdate = 0;
float simulatedTemp = 24.5;
float simulatedPressure = 101.3;

void drawDashboardLayout() {
  tft.fillScreen(ILI9341_BLACK);

  // Header banner
  tft.fillRect(0, 0, 320, 30, ILI9341_NAVY);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 7);
  tft.print("TELEMETRY DASHBOARD");

  // Grid divisions
  tft.drawFastHLine(0, 30, 320, ILI9341_CYAN);
  tft.drawFastVLine(160, 30, 180, ILI9341_DARKGREY);
  tft.drawFastHLine(0, 210, 320, ILI9341_DARKGREY);

  // Left card: Temperature
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_LIGHTGREY);
  tft.setCursor(15, 42);
  tft.print("TEMPERATURE");

  // Right card: Pressure
  tft.setCursor(175, 42);
  tft.print("PRESSURE");

  // Footer status bar
  tft.setTextColor(ILI9341_GREEN);
  tft.setCursor(10, 220);
  tft.print("STATUS: ONLINE  |  NODE: ESP32-01");
}

void updateReadings() {
  // Update Temperature display
  tft.fillRect(15, 65, 130, 40, ILI9341_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_ORANGE);
  tft.setCursor(15, 70);
  tft.printf("%.1f C", simulatedTemp);

  // Update Pressure display
  tft.fillRect(175, 65, 130, 40, ILI9341_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setCursor(175, 70);
  tft.printf("%.1f kPa", simulatedPressure);

  // Progress Bar for Temperature
  int barWidth = (int)((simulatedTemp / 50.0) * 130.0);
  if (barWidth > 130) barWidth = 130;
  tft.drawRect(15, 130, 132, 16, ILI9341_WHITE);
  tft.fillRect(16, 131, barWidth, 14, ILI9341_RED);
}

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);

  // Apply mirror fix
  tft.writeCommand(0x36);
  SPI.transfer(0x88);

  drawDashboardLayout();
}

void loop() {
  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();

    // Simulated variation for benchmark demonstration
    simulatedTemp += 0.2;
    if (simulatedTemp > 45.0) simulatedTemp = 20.0;

    simulatedPressure = 101.3 + (random(-10, 10) * 0.05);

    updateReadings();
  }
}
