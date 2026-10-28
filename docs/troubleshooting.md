# Troubleshooting Guide

### 1. Mirrored / Backwards Text
- **Cause:** Some display manufacturers configure panel gate/source drivers in reverse scan order.
- **Solution:** Execute the hardware MADCTL overwrite included in the firmware:
  ```cpp
  tft.writeCommand(0x36);
  SPI.transfer(0x88); // Or try 0x48 / 0x28
  ```

### 2. Solid White Screen
- **Cause:** Display backlight is receiving power, but SPI data lines (CS, DC, MOSI, SCK, RST) are not communicating.
- **Checklist:**
  - Verify CS is connected to GPIO 5.
  - Verify DC is connected to GPIO 2.
  - Verify RST is connected to GPIO 4 (not left floating).
  - Verify MOSI is connected to GPIO 23 and SCK to GPIO 18.
  - Ensure ground is common between ESP32 and display module.

### 3. Display Flickering
- **Cause:** Insufficient current on the 3.3V rail.
- **Solution:** Power the display backlight pin (`LED`) through a separate 3.3V regulator or an external 5V-to-3.3V LDO.
