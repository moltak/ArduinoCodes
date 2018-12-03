#include "wifi.h"
#include "lcd.h"

#include "SECRET.h"

const char* ssid = STASSID;
const char* password = STAPSK;

void connectWifi() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  printToLcd(0, 0, "Connecting wifi   ");
  printToLcd(1, 0, String("SSID: ") + ssid);

  /** 
   * Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
   * would try to act as both a client and an access-point and could cause
   * network-issues with your other WiFi-devices on your WiFi-network. 
   */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  printToLcd(0, 0, "Connected wifi   ");
  printToLcd(1, 0, WiFi.localIP().toString());
}
