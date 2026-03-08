/*
 * Project 8 — Wi-Fi Controlled Servo Motor (SG90)
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   SG90 Servo VCC    → 5V (VIN or external — NOT 3.3V)
 *   SG90 Servo GND    → GND
 *   SG90 Servo Signal → GPIO 14
 *
 * Library required: ESP32Servo by Kevin Harrington
 * Usage: Upload → note IP → open browser → click angle buttons
 */

#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

#define SERVO_PIN 14

Servo myServo;
WebServer server(80);
int currentAngle = 90;

// ── Build HTML page ───────────────────────────────────────────────────────────
String getHTML() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>Servo Control</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:20px;}";
  page += "button{padding:14px 28px;margin:8px;font-size:1.1rem;border:none;";
  page += "border-radius:8px;cursor:pointer;background:#1565C0;color:#fff;}</style></head><body>";
  page += "<h1>⚙️ Servo Motor Control</h1>";
  page += "<p>Current angle: <strong>" + String(currentAngle) + "°</strong></p>";
  page += "<a href='/0'>  <button>0°</button></a>";
  page += "<a href='/90'> <button>90°</button></a>";
  page += "<a href='/180'><button>180°</button></a>";
  page += "</body></html>";
  return page;
}

// ── Route handlers ───────────────────────────────────────────────────────────
void h0()   { currentAngle =   0; myServo.write(currentAngle); server.send(200, "text/html", getHTML()); }
void h90()  { currentAngle =  90; myServo.write(currentAngle); server.send(200, "text/html", getHTML()); }
void h180() { currentAngle = 180; myServo.write(currentAngle); server.send(200, "text/html", getHTML()); }

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  myServo.write(90);   // Centre on start

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/",    []() { server.send(200, "text/html", getHTML()); });
  server.on("/0",   h0);
  server.on("/90",  h90);
  server.on("/180", h180);
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  server.handleClient();
}
