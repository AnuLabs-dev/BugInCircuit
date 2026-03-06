# 🐛 ANU Electronics — Bug in Circuit IoT Kit

> **Complete digital manual for Kickstarter backers** · 7 Parts · 12 IoT Projects · 12 PCB Bugs · ESP32

---

## 📦 What's In This Repository

This repository contains the complete manual and reference materials for the **ANU Electronics Bug-in-Circuit IoT Kit**. Everything you need to debug the PCBs and build all 12 IoT projects is here.

| File / Folder | Description |
|------|-------------|
| `BugInCircuitComplete_Manual.html` | Full interactive manual (open in any browser) |
| `QUICK_START.md` | Get started in 5 minutes |
| `BUGS_REFERENCE.md` | All 12 bugs across the 3 PCBs |
| `PROJECTS_REFERENCE.md` | All 12 IoT projects — pin maps & summaries |
| `RESISTOR_COLOR_CODE.md` | Resistor color coding cheat sheet |
| `LIBRARIES.md` | Required Arduino libraries & install guide |
| `DESIGN_FILES.md` | PCB design files guide — folder structure & how to order PCBs |
| `Bug In Circuit Design Files/2 Chanel_Relay/` | 2-Ch board — Schematic, BOM, Gerbers, 2D/3D images |
| `Bug In Circuit Design Files/4 Chanel_Relay/` | 4-Ch board — Schematic, BOM, Gerbers, 2D/3D images |
| `Bug In Circuit Design Files/6 Chanel_Relay/` | 6-Ch board — Schematic, BOM, Gerbers, 2D/3D images |

---

## 🚀 Quick Start

1. **Open the manual** → Download and open `ANU_Electronics_Complete_Manual.html` in Chrome or Firefox  
2. **Set up Arduino IDE** → See [QUICK_START.md](QUICK_START.md) or Part 2 of the manual  
3. **Debug your PCB** → See [BUGS_REFERENCE.md](BUGS_REFERENCE.md) or Part 3 of the manual  
4. **Build IoT Projects** → See [PROJECTS_REFERENCE.md](PROJECTS_REFERENCE.md) or Parts 4–6 of the manual  

---

## 🧰 Kit Contents

| Component | Details |
|-----------|---------|
| ESP32 Dev Board | Main MCU — Wi-Fi + BT + dual-core 240 MHz |
| Relay Modules | 5V relay with optocoupler + flyback diode |
| LEDs (Red + Blue) | Indicator LEDs |
| Resistors | 220Ω, 470Ω, 1KΩ, 10KΩ |
| BC547 Transistors | NPN relay driver |
| PH1U Optocouplers | ESP32-to-relay isolation |
| Flyback Diodes | Back-EMF protection |
| Soil Moisture Sensor | Analog output |
| PIR Sensor HC-SR501 | Motion detection |
| Gas Sensor MQ-2/5 | Analog gas sensor |
| DHT11 Sensor | Temperature + Humidity |
| HC-SR04 Ultrasonic | Distance measurement |
| 28BYJ-48 Stepper | 5V stepper + ULN2003 driver |
| SG90 Servo Motor | PWM servo |
| 16×2 I2C LCD | I2C display, address 0x27 |
| IR Sensor Module | Object detection |
| Active Buzzer | Audio alerts |
| Breadboard + Jumpers | Prototyping |

---

## 📋 Manual Contents

| Part | Topic |
|------|-------|
| Part 1 | Kit Overview — Introduction & Components |
| Part 2 | ESP32 & Arduino IDE Setup |
| Part 3 | PCB Bug Correction (2-Ch / 4-Ch / 6-Ch) |
| Part 4 | IoT Projects 1–6 |
| Part 5 | IoT Projects 7–12 |
| Part 6 | ThingSpeak Cloud IoT |
| Part 7 | Resistor Color Coding Reference |

---

## ⚡ ESP32 GPIO Quick Reference (This Kit)

| GPIO | Used For | Notes |
|------|----------|-------|
| GPIO 2 | Red LED / Onboard LED | Onboard LED on most boards |
| GPIO 4 | Blue LED / Buzzer | General output |
| GPIO 5 | Stepper IN2 / Buzzer | General output |
| GPIO 14 | Servo Signal / Ultrasonic TRIG | PWM capable |
| GPIO 15 | DHT11 Data | Digital data line |
| GPIO 17 | Stepper IN4 | ULN2003 driver |
| GPIO 18 | Stepper IN3 | ULN2003 driver |
| GPIO 19 | Stepper IN1 | ULN2003 driver |
| GPIO 21 | I2C SDA (LCD) | Default SDA |
| GPIO 22 | I2C SCL (LCD) | Default SCL |
| GPIO 27 | PIR / Ultrasonic ECHO / IR Sensor | Digital input |
| GPIO 34 | Soil Sensor AO / Gas Sensor AO | Input-only ADC |

> ⚠️ GPIO 34, 35, 36, 39 are **input-only**. Avoid GPIO 0, 2, 15 for custom use — they affect boot mode.

---

## 🙏 For Kickstarter Backers

Thank you for backing the ANU Electronics Bug-in-Circuit IoT Kit! This repository is your permanent home for all kit resources. If you run into any issues:

- 📖 Check the relevant section in the HTML manual first
- 🐛 For PCB issues, refer to [BUGS_REFERENCE.md](BUGS_REFERENCE.md)
- 💬 Open a [GitHub Issue](../../issues) with your question

---

## 🗂️ PCB Design Files

All PCB design resources are available directly in this repository — browse schematics, BOMs, Gerbers, and board images without downloading anything:

| Board | Schematics | BOM | Gerber | 2D/3D Images |
|-------|-----------|-----|--------|--------------|
| [2-Channel Relay](Bug%20In%20Circuit%20Design%20Files/2%20Chanel_Relay/) | ✅ PDF | ✅ CSV | ✅ | ✅ |
| [4-Channel Relay](Bug%20In%20Circuit%20Design%20Files/4%20Chanel_Relay/) | ✅ PDF | ✅ CSV | ✅ | ✅ |
| [6-Channel Relay](Bug%20In%20Circuit%20Design%20Files/6%20Chanel_Relay/) | ✅ PDF | ✅ CSV | ✅ | ✅ |

See [DESIGN_FILES.md](DESIGN_FILES.md) for the full folder structure, file type explanations, and how to send Gerbers to a PCB manufacturer.

---

## 📄 License

This manual and all associated materials are provided exclusively for ANU Electronics kit owners. Redistribution is not permitted.

---

*ANU Electronics · Bug in Circuit IoT Kit · Complete Digital Manual*  
*ESP32 · Arduino IDE · ThingSpeak · 12 IoT Projects*
