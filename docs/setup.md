# Setup & Installation Guide

### Software Prerequisites
1. **Arduino IDE 2.3+**
2. **ESP32 Core for Arduino:**
   - In Arduino IDE, go to `Preferences` -> `Additional Board Manager URLs`.
   - Add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - In `Tools` -> `Board` -> `Boards Manager`, install **esp32 by Espressif Systems**.
3. **Libraries:**
   - Go to `Sketch` -> `Include Library` -> `Manage Libraries...`
   - Search and install: **Adafruit GFX Library**
   - Search and install: **Adafruit ILI9341**

### Verification Procedure
1. Wire the ESP32 and ILI9341 as documented in `hardware/wiring.md`.
2. Connect ESP32 via USB and select the appropriate COM port.
3. Open `firmware/baseline_test/baseline_test.ino`.
4. Compile and upload.
5. The screen should immediately turn white, draw red and blue borders, and display "ENGR HANIF KHAN".
