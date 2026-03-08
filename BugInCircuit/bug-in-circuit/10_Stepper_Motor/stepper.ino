/*
 * Project 10 — Wi-Fi Controlled Stepper Motor (28BYJ-48 + ULN2003)
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   ULN2003 IN1 → GPIO 19
 *   ULN2003 IN2 → GPIO 5
 *   ULN2003 IN3 → GPIO 18
 *   ULN2003 IN4 → GPIO 17
 *   Motor VCC   → 5V external supply
 *   Motor GND   → GND (shared with ESP32)
 *
 * Library required: Built-in Arduino Stepper library
 * Usage: Upload → note IP → browser buttons: CW / CCW / Stop
 *
 * NOTE: Use an external 5V supply for the stepper — do NOT power
 *       the 28BYJ-48 directly from the ESP32's 3.3V pin.
 */

#include <WiFi.h>
#include <WebServer.h>
#include <Stepper.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

// 28BYJ-48: 2048 steps/revolution at half-step
#define STEPS_PER_REV 2048
Stepper motor(STEPS_PER_REV, 19, 5, 18, 17);

WebServer server(80);
bool running  = false;
int  direction = 1;   // +1 = CW, -1 = CCW

// ── Build HTML page ───────────────────────────────────────────────────────────
String getHTML() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>Stepper Motor</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:20px;}";
  page += "button{padding:14px 28px;margin:8px;font-size:1rem;border:none;";
  page += "border-radius:8px;cursor:pointer;color:#fff;}";
  page += ".cw{background:#1565C0;}.ccw{background:#6a1b9a;}.stop{background:#c62828;}</style></head><body>";
  page += "<h1>🔄 Stepper Motor</h1>";
  page += "<p>Status: <strong>" + String(running ? (direction > 0 ? "Running CW" : "Running CCW") : "Stopped") + "</strong></p>";
  page += "<a href='/cw'>  <button class='cw'>▶ Clockwise</button></a>";
  page += "<a href='/ccw'><button class='ccw'>◀ Counter-CW</button></a>";
  page += "<a href='/stop'><button class='stop'>⏹ Stop</button></a>";
  page += "</body></html>";
  return page;
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  motor.setSpeed(10);   // RPM

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/",    []() { server.send(200, "text/html", getHTML()); });
  server.on("/cw",  []() { running = true;  direction =  1; server.send(200, "text/html", getHTML()); });
  server.on("/ccw", []() { running = true;  direction = -1; server.send(200, "text/html", getHTML()); });
  server.on("/stop",[]() { running = false;               server.send(200, "text/html", getHTML()); });
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  server.handleClient();
  if (running) {
    motor.step(direction * 512);   // 1/4 revolution per button press
  }
}
