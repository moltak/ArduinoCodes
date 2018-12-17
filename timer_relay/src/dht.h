#ifndef __DHT_H__
#define __DHT_H__

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "wemos_d1.h"

#define DHTPIN  D12
#define DHTTYPE DHT11

float humidity(DHT_Unified &dht);

float temperature(DHT_Unified &dht);

#endif