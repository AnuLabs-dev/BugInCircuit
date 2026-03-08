/*
 * Project 2 — Bluetooth LED Control
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   Red LED  → GPIO 2 via 220Ω → GND
 *   Blue LED → GPIO 4 via 220Ω → GND
 *
 * Usage:
 *   1. Install "Serial Bluetooth Terminal" app on Android
 *   2. Pair with "ESP32BT"
 *   3. Send characters:
 *        R → Red LED ON    r → Red LED OFF
 *        B → Blue LED ON   b → Blue LED OFF
 *
 * NOTE: BluetoothSerial is only available on ESP32 (not ESP32-S2/S3).
 */

#include "BluetoothSerial.h"

BluetoothSerial BT;

#define RED_LED  2
#define BLUE_LED 4

void setup() {
  Serial.begin(9600);
  BT.begin("ESP32BT");   // Bluetooth device name
  pinMode(RED_LED,  OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.println("Bluetooth started. Pair with 'ESP32BT'.");
}

void loop() {
  if (BT.available()) {
    char c = BT.read();
    switch (c) {
      case 'R': digitalWrite(RED_LED,  HIGH); BT.println("Red ON");   break;
      case 'r': digitalWrite(RED_LED,  LOW);  BT.println("Red OFF");  break;
      case 'B': digitalWrite(BLUE_LED, HIGH); BT.println("Blue ON");  break;
      case 'b': digitalWrite(BLUE_LED, LOW);  BT.println("Blue OFF"); break;
      default:  BT.println("Unknown command. Use R/r/B/b");           break;
    }
  }
}
