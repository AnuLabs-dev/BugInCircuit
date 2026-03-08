/*
 * Project 3 — Soil Moisture Monitor
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   Soil Moisture Sensor VCC → 3.3V
 *   Soil Moisture Sensor GND → GND
 *   Soil Moisture Sensor AO  → GPIO 34
 *
 * Thresholds (tune to your sensor):
 *   > 2500  → Dry
 *   1500–2500 → Moist
 *   < 1500  → Wet
 *
 * Output: Serial Monitor at 9600 baud
 */

#define SOIL_PIN 34   // ADC input-only pin

void setup() {
  Serial.begin(9600);
  Serial.println("Soil Moisture Monitor started.");
}

void loop() {
  int raw = analogRead(SOIL_PIN);

  String status;
  if      (raw > 2500) status = "DRY   — Please water the plant!";
  else if (raw > 1500) status = "MOIST — Soil moisture is OK.";
  else                  status = "WET   — Soil is well watered.";

  Serial.print("Raw ADC: ");
  Serial.print(raw);
  Serial.print(" | Status: ");
  Serial.println(status);

  delay(1000);
}
