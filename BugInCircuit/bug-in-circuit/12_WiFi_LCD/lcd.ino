/*
 * Project 12 — Wi-Fi Controlled 16×2 LCD Display
 * ANU Electronics — Bug in Circuit IoT Kit
 *
 * Hardware:
 *   16×2 I2C LCD VCC → 3.3V or 5V
 *   16×2 I2C LCD GND → GND
 *   16×2 I2C LCD SDA → GPIO 21
 *   16×2 I2C LCD SCL → GPIO 22
 *
 * Library required: LiquidCrystal I2C by Frank de Brabander
 * Default I2C address: 0x27
 *   If LCD is unresponsive, run I2C Scanner sketch to find the address.
 *
 * Usage: Upload → note IP → open browser → type message → click Set
 */

#include <WiFi.h>
#include <WebServer.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS  2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
WebServer server(80);
String currentMsg = "Hello World!";

// ── Build HTML page ───────────────────────────────────────────────────────────
String getHTML() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>LCD Display</title>";
  page += "<style>body{font-family:sans-serif;text-align:center;padding:20px;}";
  page += "input{padding:10px;font-size:1rem;width:80%;border-radius:6px;border:1px solid #ccc;}";
  page += "button{padding:10px 24px;background:#1565C0;color:#fff;border:none;";
  page += "border-radius:6px;cursor:pointer;margin-top:10px;font-size:1rem;}";
  page += ".lcd{font-family:monospace;background:#333;color:#0f0;border-radius:8px;";
  page += "padding:12px 16px;display:inline-block;font-size:1.2rem;margin:16px 0;}</style></head><body>";
  page += "<h1>🖥️ Wi-Fi LCD Control</h1>";
  page += "<div class='lcd'>" + currentMsg.substring(0, 16) + "</div><br>";
  page += "<form action='/set' method='GET'>";
  page += "<input name='msg' maxlength='32' value='" + currentMsg + "' placeholder='Enter message...'><br>";
  page += "<button type='submit'>📤 Send to LCD</button></form>";
  page += "</body></html>";
  return page;
}

// ── Route handler — set message ───────────────────────────────────────────────
void handleSet() {
  if (server.hasArg("msg")) {
    currentMsg = server.arg("msg");
    lcd.clear();
    // Line 1: first 16 chars
    lcd.setCursor(0, 0);
    lcd.print(currentMsg.substring(0, min((int)currentMsg.length(), 16)));
    // Line 2: chars 16–32
    if (currentMsg.length() > 16) {
      lcd.setCursor(0, 1);
      lcd.print(currentMsg.substring(16, min((int)currentMsg.length(), 32)));
    }
    Serial.println("LCD updated: " + currentMsg);
  }
  server.send(200, "text/html", getHTML());
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.print("ANU Electronics");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  String ip = WiFi.localIP().toString();
  Serial.println("\nConnected! IP: " + ip);

  lcd.clear();
  lcd.print("IP:");
  lcd.setCursor(0, 1);
  lcd.print(ip);

  server.on("/",    []() { server.send(200, "text/html", getHTML()); });
  server.on("/set", handleSet);
  server.begin();
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  server.handleClient();
}
