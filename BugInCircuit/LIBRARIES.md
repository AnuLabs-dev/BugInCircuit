# 📚 Required Libraries

All Arduino libraries needed for this kit, and how to install them.

---

## How to Install

**Method 1 — Library Manager (recommended)**
1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for the library name below → click **Install**

**Method 2 — ZIP Install**
1. Download the library ZIP from GitHub
2. Go to **Sketch → Include Library → Add .ZIP Library**
3. Select the downloaded file

---

## Library List

| Library Name | Search Term | Used In | Notes |
|---|---|---|---|
| ESP32 Board Package | `esp32` (Boards Manager) | All projects | By Espressif Systems. Install via Boards Manager, not Library Manager |
| DHT sensor library | `DHT sensor library` | Project 6 | By Adafruit |
| Adafruit Unified Sensor | `Adafruit Unified Sensor` | Project 6 | Required dependency for DHT |
| LiquidCrystal I2C | `LiquidCrystal I2C` | Project 12 | By Frank de Brabander |
| ESP32Servo | `ESP32Servo` | Project 8 | Servo control on ESP32 PWM channels |
| Stepper | Built-in | Project 10 | Already included with Arduino IDE |

---

## ESP32 Board Package Installation

1. Open Arduino IDE → **File → Preferences**
2. In *Additional Boards Manager URLs*, add:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. **Tools → Board → Boards Manager** → search `esp32`
4. Install **ESP32 by Espressif Systems** (version 2.x or later recommended)
5. **Tools → Board** → select **ESP32 Dev Module**

---

## Built-in Libraries (No Install Needed)

These are included with the ESP32 board package automatically:

- `WiFi.h` — Wi-Fi connectivity
- `WebServer.h` — HTTP web server
- `BluetoothSerial.h` — Bluetooth Classic serial
- `HTTPClient.h` — HTTP client (for ThingSpeak)
- `Wire.h` — I2C communication

---

## Troubleshooting

| Issue | Fix |
|---|---|
| `#include` error for WiFi.h | Make sure ESP32 board package is installed, not just Arduino Uno/Nano |
| DHT library not found | Install both `DHT sensor library` AND `Adafruit Unified Sensor` |
| LCD shows garbage or nothing | Confirm I2C address is 0x27; run I2C scanner sketch |
| Servo jitter | Use external 5V for servo power; do not power from ESP32 3.3V pin |

---

*Back to [README](README.md)*
