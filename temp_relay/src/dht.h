#ifndef __DHT_H__
#define __DHT_H__

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "wemos_d1.h"

#define DHTTYPE DHT11

class DhtClass
{
  public:
    DhtClass(int pin);
    void begin();
    float humidity();
    float temperature();
    DHT_Unified* dht();

  private:
    DHT_Unified *dhtModule;//(DHTPIN, DHTTYPE);
};

#endif