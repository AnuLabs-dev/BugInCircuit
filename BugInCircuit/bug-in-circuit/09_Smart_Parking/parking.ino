/*
 * Project 9 — Smart Garage Parking Assistant (HC-SR04)
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   HC-SR04 VCC  → 5V
 *   HC-SR04 GND  → GND
 *   HC-SR04 TRIG → GPIO 14
 *   HC-SR04 ECHO → GPIO 27
 *   Green LED    → GPIO 2 via 220Ω → GND  (Safe — space available)
 *   Red LED      → GPIO 4 via 220Ω → GND  (Stop — too close)
 *   Active Buzzer→ GPIO 5 → GND
 *
 * Logic:
 *   Distance < 20 cm → Red ON, Buzzer ON  (too close, stop!)
 *   Distance ≥ 20 cm → Green ON           (safe to park)
 */

#define TRIG_PIN   14
#define ECHO_PIN   27
#define GREEN_LED   2
#define RED_LED     4
#define BUZZER      5

#define STOP_DIST  20   // cm — object closer than this triggers alert

// ── Measure distance using HC-SR04 ──────────────────────────────────────────
long getDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);  // 30ms timeout
  return duration * 0.034 / 2;
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN,  OUTPUT);
  pinMode(ECHO_PIN,  INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED,   OUTPUT);
  pinMode(BUZZER,    OUTPUT);
  Serial.println("Smart Parking Assistant ready.");
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  long dist = getDistanceCm();

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.print(" cm — ");

  if (dist > 0 && dist < STOP_DIST) {
    // Too close — alert
    digitalWrite(RED_LED,   HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER, 1000);
    Serial.println("STOP! Too close.");
  } else {
    // Safe
    digitalWrite(RED_LED,   LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);
    Serial.println("Safe to park.");
  }

  delay(200);
}
