/*
 * Project 5 — Gas Leakage Detection
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   MQ-2 / MQ-5 Gas Sensor VCC → 5V
 *   MQ-2 / MQ-5 Gas Sensor GND → GND
 *   MQ-2 / MQ-5 Sensor AO     → GPIO 34
 *   Alert LED                  → GPIO 2 via 220Ω → GND
 *
 * NOTE: Allow 20–30 sec warm-up after power-on before readings stabilise.
 *       Adjust THRESHOLD to suit your environment and sensor model.
 */

#define GAS_PIN   34
#define LED_PIN    2
#define THRESHOLD 1500   // Tune: higher = less sensitive

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Gas Leakage Detector started.");
  Serial.println("Warming up sensor — please wait 30 seconds...");
  delay(30000);
  Serial.println("Ready! Monitoring for gas.");
}

void loop() {
  int gasLevel = analogRead(GAS_PIN);

  Serial.print("Gas ADC: ");
  Serial.print(gasLevel);

  if (gasLevel > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println(" | ⚠️  GAS LEAK DETECTED! Ventilate immediately!");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println(" | ✅  Air Normal");
  }

  delay(1000);
}
