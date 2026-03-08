/*
 * Project 11 — Smart IR Attendance System
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   IR Sensor VCC → 3.3V or 5V
 *   IR Sensor GND → GND
 *   IR Sensor OUT → GPIO 27
 *
 * Logic:
 *   OUT goes LOW when object/person is detected.
 *   Each detection (LOW → HIGH edge handled) increments count.
 *   Count and log are served over Wi-Fi.
 */

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

#define IR_PIN 27

WebServer server(80);
int  count   = 0;
bool detected = false;
String log_entries = "";

// ── Build HTML page ───────────────────────────────────────────────────────────
String getHTML() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='2'>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>IR Attendance</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:20px;}";
  page += ".count{font-size:4rem;color:#1565C0;font-weight:bold;}";
  page += ".log{text-align:left;max-width:400px;margin:auto;background:#f5f5f5;";
  page += "border-radius:8px;padding:12px;font-size:.9rem;max-height:200px;overflow-y:auto;}</style></head><body>";
  page += "<h1>📋 IR Attendance System</h1>";
  page += "<p class='count'>" + String(count) + "</p>";
  page += "<p>Total entries detected</p>";
  page += "<a href='/reset'><button style='padding:10px 24px;background:#c62828;color:#fff;border:none;border-radius:6px;cursor:pointer;'>Reset Count</button></a>";
  page += "<h3 style='margin-top:20px;'>Log</h3>";
  page += "<div class='log'>" + (log_entries.length() > 0 ? log_entries : "No entries yet.") + "</div>";
  page += "</body></html>";
  return page;
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", []() { server.send(200, "text/html", getHTML()); });
  server.on("/reset", []() {
    count = 0;
    log_entries = "";
    server.send(200, "text/html", getHTML());
  });
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  // Detect falling edge (object breaks beam → LOW)
  if (digitalRead(IR_PIN) == LOW && !detected) {
    count++;
    detected = true;
    String entry = "Entry #" + String(count) + "<br>";
    log_entries = entry + log_entries;   // newest first
    Serial.println("Detected! Count: " + String(count));
  }
  // Reset latch when beam is clear again
  if (digitalRead(IR_PIN) == HIGH) {
    detected = false;
  }

  server.handleClient();
  delay(100);
}
