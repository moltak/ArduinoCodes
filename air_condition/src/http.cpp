#include "http.h"
#include "SECRET.h"
#include "wifi.h"

const String BASE_URL = "openAPI.seoul.go.kr";
const String SUFFIX_URL = "/json/RealtimeCityAir/1/5/";
const int PORT = 8088;

String httpRequestUrl()
{
  return BASE_URL;
}

String getRequest(String area, String town)
{
  String url = "/" + String(API_KEY) + SUFFIX_URL + area + "/" + town;

  return String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + BASE_URL + "\r\n" +
         "User-Agent: ESP8266\r\n" +
         "Connection: close\r\n\r\n";
}

FineParticle requestAirCondition(String area, String town)
{
  struct FineParticle fp;

  WiFiClient client;

  if (!client.connect(httpRequestUrl(), PORT))
  {
    fp.error = "Error while connecting AirCondition server";
    return fp;
  }

  client.print(getRequest(area, town));

  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    if (line == "\r")
    {
      Serial.println("headers received");
      break;
    }
  }

  String raw = client.readString();

  StaticJsonBuffer<400> jsonBuffer;
  String extracted = raw.substring(raw.indexOf("[") + 1, raw.indexOf("]"));
  JsonObject &root = jsonBuffer.parseObject(extracted);

  Serial.println(raw);
  Serial.println(extracted);
  Serial.println(String("Parsing Success: ") + root.success());

  fp.pm25 = (int)root["PM25"];
  fp.pm10 = (int)root["PM10"];

  return fp;
}
