/*
 * Project 1 — Wi-Fi Based LED Control
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   Red LED  → GPIO 2 via 220Ω → GND
 *   Blue LED → GPIO 4 via 220Ω → GND
 *
 * Usage:
 *   1. Upload sketch → open Serial Monitor → note IP address
 *   2. Open browser on same Wi-Fi → enter IP
 *   3. Click ON/OFF buttons to toggle LEDs
 */

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

WebServer server(80);

#define R 2   // Red LED
#define B 4   // Blue LED

// ── HTML page ────────────────────────────────────────────────────────────────
String getHTML() {
  return R"rawliteral(
<!DOCTYPE html><html>
<head><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Wi-Fi LED Control</title>
<style>
  body{font-family:sans-serif;text-align:center;padding:20px;}
  button{padding:12px 28px;margin:8px;font-size:1rem;border:none;
         border-radius:6px;cursor:pointer;color:#fff;}
  .on {background:#2e7d32;} .off{background:#c62828;}
</style></head>
<body>
<h2>🔴 Red LED</h2>
<a href="/ron"> <button class="on">ON</button></a>
<a href="/roff"><button class="off">OFF</button></a>
<h2>🔵 Blue LED</h2>
<a href="/bon"> <button class="on">ON</button></a>
<a href="/boff"><button class="off">OFF</button></a>
</body></html>
)rawliteral";
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/",    []() { server.send(200, "text/html", getHTML()); });
  server.on("/ron",  []() { digitalWrite(R, HIGH); server.send(200, "text/html", getHTML()); });
  server.on("/roff", []() { digitalWrite(R, LOW);  server.send(200, "text/html", getHTML()); });
  server.on("/bon",  []() { digitalWrite(B, HIGH); server.send(200, "text/html", getHTML()); });
  server.on("/boff", []() { digitalWrite(B, LOW);  server.send(200, "text/html", getHTML()); });
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  server.handleClient();
}
