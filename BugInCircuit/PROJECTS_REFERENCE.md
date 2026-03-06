# 📡 IoT Projects Reference — All 12 Projects

Pin connections and summaries for every project in the kit.

---

## Project 1 — Wi-Fi LED Control

**Tags:** Wi-Fi, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| Red LED Anode | GPIO 2 via 220Ω |
| Blue LED Anode | GPIO 4 via 220Ω |
| All Cathodes | GND |

**Steps:** Upload sketch → Serial Monitor → note IP → open browser on same Wi-Fi → click ON/OFF buttons.

---

## Project 2 — Bluetooth LED Control

**Tags:** Bluetooth Classic, Serial BT

| Device / Pin | ESP32 Pin |
|---|---|
| Red LED | GPIO 2 |
| Blue LED | GPIO 4 |

**Steps:** Upload → pair phone to ESP32 Bluetooth → use a serial BT app → send `1`/`0` to toggle LEDs.

---

## Project 3 — Soil Moisture Monitor

**Tags:** Analog Sensor, ADC

| Device / Pin | ESP32 Pin |
|---|---|
| Sensor VCC | 3.3V |
| Sensor GND | GND |
| Sensor AO | GPIO 34 |

> GPIO 34 is input-only. Reads analog moisture level and prints to Serial Monitor.

---

## Project 4 — PIR Motion Detector

**Tags:** PIR, HC-SR501

| Device / Pin | ESP32 Pin |
|---|---|
| PIR VCC | 5V |
| PIR GND | GND |
| PIR OUT | GPIO 27 |
| LED | GPIO 2 |

Motion detected → LED turns ON → alert printed to Serial Monitor.

---

## Project 5 — Gas Leakage Alarm

**Tags:** MQ-2/MQ-5, Analog, Buzzer

| Device / Pin | ESP32 Pin |
|---|---|
| Gas Sensor VCC | 5V |
| Gas Sensor AO | GPIO 34 |
| Buzzer | GPIO 4 |

Reads analog gas concentration. If above threshold → buzzer triggers.

---

## Project 6 — Smart Plant Monitor

**Tags:** DHT11, Soil Sensor, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| DHT11 Data | GPIO 15 |
| Soil Sensor AO | GPIO 34 |
| DHT11 VCC | 3.3V |

Hosts a Wi-Fi webpage showing live temperature, humidity, and soil moisture.

---

## Project 7 — Wi-Fi Security System

**Tags:** PIR, Buzzer, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| PIR OUT | GPIO 27 |
| Buzzer | GPIO 4 |
| LED | GPIO 2 |

Motion detection triggers buzzer + LED alarm. Status visible on web dashboard.

---

## Project 8 — Wi-Fi Servo Motor Control

**Tags:** SG90, PWM, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| Servo VCC | 5V (VIN or external) |
| Servo GND | GND |
| Servo Signal | GPIO 14 |

> ⚠️ Power servo from VIN or external 5V — 3.3V is insufficient for SG90.

Web routes `/0`, `/90`, `/180` set servo angle.

---

## Project 9 — Smart Parking Assistant

**Tags:** HC-SR04, Ultrasonic, Buzzer

| Device / Pin | ESP32 Pin |
|---|---|
| HC-SR04 VCC | 5V |
| TRIG | GPIO 14 |
| ECHO | GPIO 27 |
| Green LED | GPIO 2 |
| Red LED | GPIO 4 |
| Buzzer | GPIO 5 |

Distance < 20 cm → Red LED + buzzer active. Distance ≥ 20 cm → Green LED, silent.

---

## Project 10 — Wi-Fi Stepper Motor Control

**Tags:** 28BYJ-48, ULN2003, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| IN1 | GPIO 19 |
| IN2 | GPIO 5 |
| IN3 | GPIO 18 |
| IN4 | GPIO 17 |
| VCC | 5V external |
| GND | GND |

Web routes `/cw` (clockwise 512 steps) and `/ccw` (counter-clockwise 512 steps).

---

## Project 11 — IR Attendance System

**Tags:** IR Sensor, Auto Count, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| IR VCC | 3.3V or 5V |
| IR GND | GND |
| IR OUT | GPIO 27 |

Each object/person crossing the IR beam increments the attendance counter. Count shown on web page and Serial Monitor.

---

## Project 12 — Wi-Fi LCD Display

**Tags:** I2C LCD, 16×2, WebServer

| Device / Pin | ESP32 Pin |
|---|---|
| LCD VCC | 3.3V or 5V |
| LCD GND | GND |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

> Default I2C address: **0x27**. Run an I2C scanner sketch if LCD does not respond.

Send custom text via web form → displayed instantly on the 16×2 LCD.

---

## ☁️ Bonus — ThingSpeak Cloud IoT

**Tags:** ThingSpeak, HTTPS, Cloud

| Device / Pin | ESP32 Pin |
|---|---|
| LED | GPIO 2 |
| Wi-Fi | Required |

**Setup:**
1. Go to [thingspeak.com](https://thingspeak.com) → create a free MathWorks account
2. Channels → New Channel → enable Field 1 → Save
3. Copy **Write API Key**, **Read API Key**, and **Channel ID**
4. Paste into the sketch and upload

ESP32 writes `field1=1` to turn LED ON, then reads back the value and acts — full two-way cloud control.

> ⏱️ Free tier minimum interval: **15 seconds**. Use `delay(20000)` in your sketch to stay within limits.

---

*Back to [README](README.md)*
