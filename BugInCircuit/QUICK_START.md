# ⚡ Quick Start Guide — ANU Electronics Bug in Circuit IoT Kit

Get up and running in 5 minutes.

---

## Step 1 — Open the Manual

Download `ANU_Electronics_Complete_Manual.html` from this repository and open it in **Chrome** or **Firefox**. No internet connection required — it's fully self-contained.

---

## Step 2 — Install Arduino IDE

1. Download Arduino IDE from [arduino.cc](https://arduino.cc)
2. Open **File → Preferences**
3. Paste this URL into *Additional Boards Manager URLs*:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager** → search `esp32` → install **ESP32 by Espressif Systems**
5. Go to **Tools → Board** → select **ESP32 Dev Module**

---

## Step 3 — Connect Your ESP32

1. Connect the ESP32 to your PC via USB
2. Go to **Tools → Port** → select the correct COM port
3. Click **Upload (→)** to flash a sketch
4. Hold the **BOOT** button if upload fails

---

## Step 4 — Install Required Libraries

Go to **Sketch → Include Library → Manage Libraries** and install:

| Library | Used In |
|---------|---------|
| `DHT sensor library` | Project 6 (Plant Monitor), DHT11 |
| `LiquidCrystal I2C` | Project 12 (LCD Display) |
| `ESP32Servo` | Project 8 (Servo Motor) |
| `Stepper` | Project 10 (Stepper Motor) |

See [LIBRARIES.md](LIBRARIES.md) for full details.

---

## Step 5 — Debug Your PCB

Refer to [BUGS_REFERENCE.md](BUGS_REFERENCE.md) for the complete list of all 12 bugs across the 2-channel, 4-channel, and 6-channel boards.

**Universal debug approach:**
1. Visual PCB inspection
2. Multimeter continuity test on supply traces
3. Activate each ESP32 output independently
4. Verify LED + relay click per channel

---

## Step 6 — Build IoT Projects

Refer to [PROJECTS_REFERENCE.md](PROJECTS_REFERENCE.md) for all 12 projects with pin connections and code snippets.

All projects follow this pattern:
1. Wire up components per the pin table
2. Update `ssid` and `pass` with your Wi-Fi credentials
3. Upload sketch → open Serial Monitor → note the IP address
4. Open a browser on the same Wi-Fi → navigate to the IP

---

## 🛟 Troubleshooting

| Problem | Fix |
|---------|-----|
| Upload fails | Hold BOOT button during upload |
| COM port not visible | Install CP2102 or CH340 USB driver |
| ESP32 not in board list | Re-check the board URL in Preferences |
| LCD shows nothing | Run I2C scanner; default address is 0x27 |
| Relay not clicking | Check power supply — relay needs 5V, not 3.3V |
| Wi-Fi not connecting | Verify SSID/password; ESP32 only supports 2.4 GHz |

---

*Back to [README](README.md)*
