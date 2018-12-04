#ifndef __HTTP_H__
#define __HTTP_H__

#include "ArduinoJson.h"

struct FineParticle {
  int pm25;
  int pm10;
  String error;
};

String httpRequestUrl();

String getRequest(String area, String town);

FineParticle requestAirCondition(String area, String town);

#endif
