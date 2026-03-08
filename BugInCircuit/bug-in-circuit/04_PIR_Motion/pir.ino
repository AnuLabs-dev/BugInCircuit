/*
 * Project 4 — PIR Motion Detection
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   PIR HC-SR501 VCC → 5V (or 3.3V)
 *   PIR HC-SR501 GND → GND
 *   PIR HC-SR501 OUT → GPIO 27
 *   Red LED          → GPIO 2 via 220Ω → GND
 *
 * NOTE: Wait 30–60 seconds after power-on for PIR calibration
 *       before testing motion detection.
 */

#define PIR_PIN 27
#define LED_PIN  2

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("PIR Motion Detector ready.");
  Serial.println("Calibrating... please wait 30 seconds.");
  delay(30000);
  Serial.println("Ready! Monitoring for motion.");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("⚠️  Motion Detected!");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("✅  No Motion");
  }
  delay(500);
}
