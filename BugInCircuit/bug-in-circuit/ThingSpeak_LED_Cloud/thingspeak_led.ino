/*
 * ThingSpeak Cloud — LED Control
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   LED (onboard or external) → GPIO 2
 *
 * Setup:
 *   1. Create a free account at thingspeak.com
 *   2. Channels → New Channel → enable Field 1 → Save
 *   3. API Keys tab → copy Write API Key and Read API Key
 *   4. Note your Channel ID from the channel page URL
 *   5. Fill in YOUR_* values below and upload
 *
 * How it works:
 *   ESP32 writes field1=1 to ThingSpeak (LED ON command),
 *   then reads back field1 and drives the LED accordingly.
 *   This demonstrates full two-way cloud communication.
 *
 * Free-tier limit: 1 message per 15 seconds minimum.
 * This sketch uses delay(20000) to stay within limits.
 */

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid    = "YOUR_WIFI_SSID";
const char* pass    = "YOUR_WIFI_PASSWORD";
String      chID    = "YOUR_CHANNEL_ID";
String      wKey    = "YOUR_WRITE_API_KEY";
String      rKey    = "YOUR_READ_API_KEY";

#define LED_PIN 2

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  HTTPClient http;

  // ── Write field1 = 1 (signal LED ON to cloud) ────────────────────────────
  String writeURL = "https://api.thingspeak.com/update?api_key=" + wKey + "&field1=1";
  http.begin(writeURL);
  int writeCode = http.GET();
  Serial.print("Write response: ");
  Serial.println(writeCode);
  http.end();
  delay(5000);

  // ── Read back field1 and drive LED accordingly ────────────────────────────
  String readURL = "https://api.thingspeak.com/channels/" + chID +
                   "/fields/1/last.txt?api_key=" + rKey;
  http.begin(readURL);
  int readCode = http.GET();
  if (readCode == 200) {
    String value = http.getString();
    value.trim();
    Serial.print("Cloud value: ");
    Serial.println(value);
    digitalWrite(LED_PIN, (value == "1") ? HIGH : LOW);
  } else {
    Serial.print("Read failed: ");
    Serial.println(readCode);
  }
  http.end();

  // ── Wait 20 sec to respect free-tier rate limit (min 15 sec) ─────────────
  delay(20000);
}
