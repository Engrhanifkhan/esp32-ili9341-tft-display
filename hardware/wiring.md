# Hardware Wiring & Interface Guide: ESP32 to ILI9341

## Connection Matrix

```text
    +-------------------+                 +-------------------+
    |    ESP32-WROOM    |                 |  2.8" SPI ILI9341 |
    |                   |                 |                   |
    |              3.3V +-----------------+ VCC               |
    |               GND +-----------------+ GND               |
    |            GPIO 5 +-----------------+ CS                |
    |            GPIO 4 +-----------------+ RESET             |
    |            GPIO 2 +-----------------+ DC / A0           |
    |           GPIO 23 +-----------------+ SDI (MOSI)        |
    |           GPIO 18 +-----------------+ SCK (CLK)         |
    |              3.3V +-----------------+ LED (Backlight)   |
    |           GPIO 19 +-----------------+ SDO (MISO - opt)  |
    +-------------------+                 +-------------------+
```

## Critical Hardware Notes
1. **Voltage Compatibility:** The ILI9341 controller core operates strictly at **3.3V logic levels**. Do not connect directly to 5V microcontrollers (e.g., Arduino Uno/Mega) without bidirectional level shifting. With ESP32, all GPIOs are natively 3.3V, making direct connection safe.
2. **Backlight LED Power:** Powering the backlight pin directly from an ESP32 GPIO is discouraged due to current draw (~45mA). Connect `LED` directly to the **3.3V rail** or drive it through a 2N2222 NPN transistor for software PWM dimming.
3. **SPI Clock Speed:** The ESP32 hardware VSPI supports clock speeds up to **40 MHz** for ILI9341. In software, this provides smooth refresh rates (~30 fps for localized updates).
