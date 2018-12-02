#include "http.h"
#include "SECRET.h"
#include "wifi.h"

const String BASE_URL = "http://openAPI.seoul.go.kr/";
const String SUFFIX_URL = "/json/RealtimeCityAir/1/5/";
const int PORT = 8088;

String httpRequestUrl(String area, String town) {
  return BASE_URL + String(API_KEY) + SUFFIX_URL + area + "/" + town;
}

FineParticle requestAirCondition(String area, String town) {
  struct FineParticle fp;

  WiFiClient client;

  if (!client.connect(httpRequestUrl(area, town), PORT)) {
    fp.error = "Error while connecting AirCondition server";
    return fp;
  }

  // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      fp.error = "Client Timeout";
      client.stop();
      return fp;
    }
  }

  String raw = "";

  while (client.available()) {
    char ch = static_cast<char>(client.read());
    raw += ch;
  }

  client.stop();

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(raw);

  fp.pm25 = root["RealtimeCityAir"]["row"][0]["PM25"];
  fp.pm10 = root["RealtimeCityAir"]["row"][0]["PM10"];

  return fp;
}
