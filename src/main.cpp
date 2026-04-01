// #include <Arduino.h>

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(115200);
//   pinMode(4, OUTPUT);
//   pinMode(23, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   Serial.println("Hello, world!");
//   digitalWrite(4, HIGH);
//   digitalWrite(23, LOW);
//   delay(1000);
//   digitalWrite(4, LOW);
//   digitalWrite(23, HIGH);
//   delay(1000);
// }

#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>

// Access Point credentials
const char *ssid = "ESP32_Server";
const char *password = "12345678";

WebServer server(80);

// LED pin
const int ledPin = 23;

// HTML page
String htmlPage()
{
  return "<!DOCTYPE html><html>\
  <head><title>ESP32 Control</title></head>\
  <body>\
  <h1>ESP32 Web Server</h1>\
  <p><a href=\"/on\"><button>Turn ON</button></a></p>\
  <p><a href=\"/off\"><button>Turn OFF</button></a></p>\
  </body></html>";
}

// Handlers
void handleRoot()
{
  server.send(200, "text/html", htmlPage());
}

void handleOn()
{
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", htmlPage());
}

void handleOff()
{
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", htmlPage());
}

void setup()
{
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  // Start Access Point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Routes
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}

void loop()
{
  server.handleClient();
}