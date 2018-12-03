#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd.h"
#include "wifi.h"
#include "http.h"

const int MIN_10 = 10 * 60 * 1000;

const char* host = "djxmmx.net";
const uint16_t port = 17;

void setup() {
  Serial.begin(9600);

  lcdSetup();
  connectWifi();

  // Use WiFiClient class to create TCP connections
  // openapi.seoul.go.kr/42477670436d6f6c37366b704c536f/json/RealtimeCityAir/1/5/동북권/성북구
  const char* host2 = "openapi.seoul.go.kr/42477670436d6f6c37366b704c536f/json/RealtimeCityAir/1/5/동북권/성북구";

  WiFiClient client;
  IPAddress remote_addr;
  Serial.println(String(" HostByName: ") + String(WiFi.hostByName(host2, remote_addr, 5000)));

  int result = client.connect(host2, 8088);
  Serial.println(String("Result: ") + String(result));
}

void loop() {
  int keyCode = analogRead(0);

  //  FineParticle fp = requestAirCondition("동북권", "성북구");
  //
  //  if (fp.error != NULL) {
  //    Serial.println(fp.error);
  //  } else {
  //    printToLcd(0, 0, "PM 2.5 " + String(fp.pm25));
  //    printToLcd(1, 0, "PM 10: " + String(fp.pm10));
  //  }

  delay(MIN_10);
}
