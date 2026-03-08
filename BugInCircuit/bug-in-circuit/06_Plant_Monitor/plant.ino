/*
 * Project 6 — Plant Monitor (DHT11 + Soil Moisture + Wi-Fi)
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   DHT11 VCC  → 3.3V
 *   DHT11 DATA → GPIO 15
 *   DHT11 GND  → GND
 *   Soil VCC   → 3.3V
 *   Soil AO    → GPIO 34
 *   Soil GND   → GND
 *
 * Libraries required: DHT sensor library by Adafruit
 * Usage: Upload → Serial Monitor → note IP → open in browser
 */

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

#define DHT_PIN  15
#define SOIL_PIN 34
#define DHTTYPE  DHT11

DHT dht(DHT_PIN, DHTTYPE);
WebServer server(80);

// ── Build HTML page with live sensor data ────────────────────────────────────
void handleRoot() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int   soil = analogRead(SOIL_PIN);

  String soilStatus;
  if      (soil > 2500) soilStatus = "🔴 Dry — Please water!";
  else if (soil > 1500) soilStatus = "🟡 Moist — OK";
  else                   soilStatus = "🟢 Wet — Well watered";

  String page = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='5'>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>Plant Monitor</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:20px;background:#f0fdf4;}";
  page += "h1{color:#2e7d32;} .card{display:inline-block;background:#fff;border-radius:12px;";
  page += "padding:16px 32px;margin:10px;box-shadow:0 2px 8px rgba(0,0,0,.1);font-size:1.1rem;}</style></head>";
  page += "<body><h1>🌿 Plant Monitor</h1>";
  page += "<div class='card'>🌡️ Temperature: <strong>" + String(temp, 1) + " °C</strong></div>";
  page += "<div class='card'>💧 Humidity: <strong>" + String(hum, 1) + " %</strong></div>";
  page += "<div class='card'>🌱 Soil: <strong>" + soilStatus + "</strong></div>";
  page += "<p style='color:#aaa;font-size:.85rem;'>Auto-refreshes every 5 seconds</p>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  server.handleClient();
}
