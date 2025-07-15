#define BLYNK_TEMPLATE_ID "TemplateID"
#define BLYNK_DEVICE_NAME "kiko"
#define BLYNK_AUTH_TOKEN "AuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your WiFi credentials
char ssid[] = "theark";
char pass[] = "ark7745";

// Blynk virtual pins
#define CURRENT_VPIN V1
#define RELAY_VPIN   V2

// Pins
const int ACS712_PIN = A0;
const int RELAY_PIN = D1;

// Calibration (adjust based on your ACS712 module)
const float sensitivity = 0.185; // for 5A version
const float vRef = 512.0; // midpoint voltage at 0 current

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Appliance OFF by default

  timer.setInterval(1000L, sendCurrent);
  Blynk.virtualWrite(RELAY_VPIN, 0); // Button OFF on start
}

void loop() {
  Blynk.run();
  timer.run();
}

// Read and send current value
void sendCurrent() {
  int sensorValue = analogRead(ACS712_PIN);
  float voltage = (sensorValue / 1024.0) * 5.0;
  float current = (voltage - 2.5) / sensitivity; // Centered at 2.5V
  current = abs(current); // Remove negative sign

  Serial.print("Current: ");
  Serial.println(current);
  Blynk.virtualWrite(CURRENT_VPIN, current);
}

// Blynk button handler
BLYNK_WRITE(RELAY_VPIN) {
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN, relayState);
}
