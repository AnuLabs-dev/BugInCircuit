# 🐛 ANU Electronics — Bug in Circuit IoT Kit

Arduino sketches for all **12 IoT Projects** included in the ANU Electronics Bug-in-Circuit ESP32 kit.

---

## 📦 Repository Structure

```
bug-in-circuit/
├── 01_WiFi_LED_Control/         wifi_led.ino
├── 02_Bluetooth_LED/            bt_led.ino
├── 03_Soil_Moisture/            soil.ino
├── 04_PIR_Motion/               pir.ino
├── 05_Gas_Leakage/              gas.ino
├── 06_Plant_Monitor/            plant.ino
├── 07_Security_System/          security.ino
├── 08_Servo_Motor/              servo.ino
├── 09_Smart_Parking/            parking.ino
├── 10_Stepper_Motor/            stepper.ino
├── 11_IR_Attendance/            attend.ino
├── 12_WiFi_LCD/                 lcd.ino
└── ThingSpeak_LED_Cloud/        thingspeak_led.ino
```

---

## ⚡ Quick Start

### 1. Arduino IDE Setup
1. Install **Arduino IDE** from [arduino.cc](https://arduino.cc)
2. **File → Preferences** → add Board URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. **Tools → Board → Boards Manager** → search `esp32` → install **ESP32 by Espressif Systems**
4. **Tools → Board** → select **ESP32 Dev Module**
5. Connect ESP32 via USB → **Tools → Port** → select correct COM port

### 2. Install Libraries
Go to **Sketch → Include Library → Manage Libraries** and install:

| Library | Used In |
|---------|---------|
| DHT sensor library (Adafruit) | Project 6 — Plant Monitor |
| LiquidCrystal I2C (Frank de Brabander) | Project 12 — LCD Display |
| ESP32Servo (Kevin Harrington) | Project 8 — Servo Motor |
| BluetoothSerial (built-in) | Project 2 — Bluetooth LED |

### 3. Configure Wi-Fi Credentials
In every Wi-Fi sketch, replace:
```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";
```

---

## 📡 Project Summary

| # | Project | Key Component | GPIO Pins |
|---|---------|--------------|-----------|
| 1 | Wi-Fi LED Control | WebServer | GPIO 2, 4 |
| 2 | Bluetooth LED | BluetoothSerial | GPIO 2, 4 |
| 3 | Soil Moisture Monitor | Analog sensor | GPIO 34 |
| 4 | PIR Motion Detection | HC-SR501 | GPIO 27, 2 |
| 5 | Gas Leakage Detection | MQ-2 / MQ-5 | GPIO 34, 2 |
| 6 | Plant Monitor (Wi-Fi) | DHT11 + Soil | GPIO 15, 34 |
| 7 | Wi-Fi Security System | PIR + Buzzer | GPIO 27, 2, 4 |
| 8 | Servo Motor (Wi-Fi) | SG90 | GPIO 14 |
| 9 | Smart Parking Assistant | HC-SR04 | GPIO 14, 27 |
| 10 | Stepper Motor (Wi-Fi) | 28BYJ-48 + ULN2003 | GPIO 19, 5, 18, 17 |
| 11 | IR Attendance System | IR Sensor | GPIO 27 |
| 12 | Wi-Fi LCD Display | 16×2 I2C LCD | GPIO 21, 22 |
| ☁️ | ThingSpeak Cloud LED | HTTPS API | GPIO 2 |

---

## 📌 ESP32 GPIO Reference (This Kit)

| GPIO | Used For | Notes |
|------|----------|-------|
| GPIO 2 | Red LED / Onboard LED | Onboard LED on most boards |
| GPIO 4 | Blue LED / Buzzer | General purpose output |
| GPIO 5 | Stepper IN2 / Buzzer | General purpose |
| GPIO 14 | Servo Signal / HC-SR04 TRIG | PWM capable |
| GPIO 15 | DHT11 Data | Digital data line |
| GPIO 17 | Stepper IN4 | ULN2003 driver |
| GPIO 18 | Stepper IN3 | ULN2003 driver |
| GPIO 19 | Stepper IN1 | ULN2003 driver |
| GPIO 21 | I2C SDA (LCD) | Default SDA |
| GPIO 22 | I2C SCL (LCD) | Default SCL |
| GPIO 27 | PIR / HC-SR04 ECHO / IR Sensor | Digital input |
| GPIO 34 | Soil AO / Gas AO | Input-only ADC pin |

> ⚠️ GPIO 34, 35, 36, 39 are **input-only**. Avoid GPIO 0, 2, 15 for custom use — they affect boot mode.

---

## ☁️ ThingSpeak Cloud Setup

1. Create a free account at [thingspeak.com](https://thingspeak.com)
2. **Channels → New Channel** → enable Field 1 → Save
3. **API Keys** tab → copy Write API Key and Read API Key
4. Note your **Channel ID** from the channel page URL
5. Paste all values into `ThingSpeak_LED_Cloud/thingspeak_led.ino`

> ⏱️ Free tier minimum interval: **15 seconds**. The sketch uses `delay(20000)` to stay safe.

---

## 🐛 PCB Bug Reference (Circuit Debugging — Part 3)

The kit contains intentional hardware faults across 3 PCB boards. Refer to the complete manual for full bug correction steps.

| Circuit | Bug Count | Common Faults |
|---------|-----------|---------------|
| 2-Channel | 2 | Missing Vcc to optocoupler, missing flyback diode |
| 4-Channel | 4 | Above + missing LED signal trace |
| 6-Channel | 6 | Above + missing transistor base connection |

**Universal debug approach:**
1. Visual PCB inspection
2. Multimeter continuity on supply traces
3. Activate each ESP32 output independently
4. Verify LED + relay click per channel

---

## 📖 Full Manual

The complete 7-part manual (kit overview, ESP32 setup, circuit debugging, IoT projects, ThingSpeak, and resistor colour coding) is available in this repository as `ANU_Electronics_Complete_Manual.html`.

---

*ANU Electronics · Bug in Circuit IoT Kit · ESP32 + Arduino IDE*
