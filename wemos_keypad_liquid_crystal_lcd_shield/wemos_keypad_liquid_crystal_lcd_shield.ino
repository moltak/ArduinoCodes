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
  const char* host2 = "openapi.seoul.go.kr//json/RealtimeCityAir/1/5/동부권/성북구";
  
  WiFiClient client;
  if (!client.connect(host2, 8088)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }

  // This will send a string to the server
  Serial.println("sending data to server");
  if (client.connected()) {
    client.println("hello from ESP8266");
  }

  // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      delay(60000);
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  Serial.println("receiving from remote server");
  // not testing 'client.connected()' since we do not need to send data here
  while (client.available()) {
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
  }

  // Close the connection
  Serial.println();
  Serial.println("closing connection");
  client.stop();
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
