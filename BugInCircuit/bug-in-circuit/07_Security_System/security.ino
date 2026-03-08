/*
 * Project 7 — Wi-Fi Security System (PIR + Buzzer)
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   PIR HC-SR501 OUT → GPIO 27
 *   LED              → GPIO 2 via 220Ω → GND
 *   Active Buzzer    → GPIO 4 → GND
 *
 * Usage: Upload → note IP → open browser → monitor alarm status
 *        Page auto-refreshes every 3 seconds.
 */

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

#define PIR_PIN 27
#define LED_PIN  2
#define BUZ_PIN  4

WebServer server(80);
String alarmStatus = "✅ Area Secure";

// ── Build HTML status page ───────────────────────────────────────────────────
String getHTML() {
  bool alarm = (alarmStatus.indexOf("MOTION") >= 0);
  String bg  = alarm ? "#fce4e4" : "#f0fdf4";
  String col = alarm ? "#c62828" : "#2e7d32";
  String page  = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='3'>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>Security System</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:30px;background:" + bg + ";}";
  page += "h2{color:" + col + ";font-size:2rem;}</style></head><body>";
  page += "<h1>🔒 Security System</h1>";
  page += "<h2>" + alarmStatus + "</h2>";
  page += "<p style='color:#888;'>Auto-refreshes every 3 seconds</p>";
  page += "</body></html>";
  return page;
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", []() { server.send(200, "text/html", getHTML()); });
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    alarmStatus = "⚠️ MOTION DETECTED!";
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZ_PIN, HIGH);
  } else {
    alarmStatus = "✅ Area Secure";
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZ_PIN, LOW);
  }
  server.handleClient();
  delay(500);
}
