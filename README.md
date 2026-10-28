# ESP32 ILI9341 SPI TFT Display Suite

![ESP32](https://img.shields.io/badge/MCU-ESP32--WROOM--32-red?style=for-the-badge&logo=espressif&logoColor=white)
![Display](https://img.shields.io/badge/Display-ILI9341_SPI_2.8%22-blue?style=for-the-badge)
![Framework](https://img.shields.io/badge/Framework-Arduino_C%2B%2B-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Status](https://img.shields.io/badge/Baseline_Hardware-Verified-brightgreen?style=for-the-badge)

A comprehensive hardware validation and graphic telemetry display suite for **ESP32-WROOM-32** interfacing with a **2.8" SPI TFT (ILI9341 controller, 320×240 resolution)**.

---

## 👨‍💻 Developer Information

- **Engineer:** Engr. Hanif Ullah (Engr. Hanif Khan)
- **Specialization:** Hardware & Embedded Systems Engineer
- **Institution:** Centre of Intelligent Systems & Network Research (CISNR), UET Peshawar
- **WhatsApp / Phone:** [+92 311 8221686](https://wa.me/923118221686)
- **LinkedIn:** [Engr. Hanif Khan](https://www.linkedin.com/in/engr-hanif-khan-628a04259/)
- **Email:** [hanifullahshams@gmail.com](mailto:hanifullahshams@gmail.com)

---

## ⚡ Hardware Pinout Configuration (ESP32-WROOM-32)

| TFT Pin | ESP32 GPIO | Direction | Function | Notes |
|---|---|---|---|---|
| **VCC** | 3.3V / 5V | Power | Power Supply | Connect to 5V if module has onboard 3.3V LDO regulator; else 3.3V |
| **GND** | GND | Power | Ground | Common system ground |
| **CS** | GPIO 5 | Output | Chip Select | Active LOW |
| **RESET** | GPIO 4 | Output | Hardware Reset | Active LOW |
| **DC** (A0) | GPIO 2 | Output | Data / Command | HIGH = Data, LOW = Command |
| **SDI (MOSI)** | GPIO 23 | Output | SPI Master Out | Hardware VSPI MOSI |
| **SCK (CLK)** | GPIO 18 | Output | SPI Clock | Hardware VSPI SCK (up to 40MHz) |
| **LED** | 3.3V | Input | Backlight | Can be driven via PWM / transistor for dimming |
| **SDO (MISO)** | GPIO 19 | Input | SPI Master In | Optional (used for reading display registers) |

---

## 🧪 Testing Status & Authenticity Disclosure

- **✅ Baseline Hardware Test (Physically Verified):**
  The baseline sketch located at `firmware/baseline_test/baseline_test.ino` has been **physically compiled and verified on an actual ESP32-WROOM-32 board**. It resolves the common ILI9341 mirror/reversed text phenomenon using low-level MADCTL command register manipulation (`0x36` with byte `0x88`).
- **⚠️ Graphic Telemetry Dashboard (Reference Implementation — Testing Pending):**
  The multi-screen telemetry dashboard in `firmware/dashboard_demo/dashboard_demo.ino` is a newly engineered **reference implementation**. It demonstrates modular UI widgets, gauges, and telemetry cards. Physical verification on hardware is currently pending.

---

## 🛠️ The ILI9341 Mirror Text Fix Explained

Certain third-party 2.8" SPI ILI9341 modules exhibit mirrored horizontal scanning when using standard `setRotation(1)`. This firmware directly configures the Memory Access Control register (MADCTL):

```cpp
// Send MADCTL command (0x36) to correct horizontal scan direction
tft.writeCommand(0x36);
SPI.transfer(0x88); // 0x88 corrects mirror flip; alternative: 0x48 or 0x28 depending on glass orientation
```

---

## 📁 Repository Structure

```text
esp32-ili9341-tft-display/
├── README.md
├── LICENSE
├── .gitignore
├── firmware/
│   ├── baseline_test/
│   │   └── baseline_test.ino       # Verified hardware test sketch
│   └── dashboard_demo/
│       └── dashboard_demo.ino      # Reference UI & telemetry benchmark (testing pending)
├── hardware/
│   ├── wiring.md                   # Full schematic pinout & level-shifting guide
│   └── components.md               # Bill of Materials
└── docs/
    ├── setup.md                    # Arduino IDE & library setup instructions
    ├── troubleshooting.md          # Mirroring, white screen, and SPI speed fixes
    └── testing-status.md           # Engineering log & verification report
```

---

## 🚀 Getting Started

1. Open **Arduino IDE** (v2.x recommended).
2. Install the **ESP32 Board Package** via Boards Manager.
3. Install required libraries:
   - **Adafruit GFX Library** (v1.11+ via Library Manager)
   - **Adafruit ILI9341** (v1.6+ via Library Manager)
4. Select board: **ESP32 Dev Module**.
5. Upload `firmware/baseline_test/baseline_test.ino` at 115200 baud.
