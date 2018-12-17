#include "dht.h"

float humidity(DHT_Unified &dht) {
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    return event.temperature;
}

float temperature(DHT_Unified &dht) {
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    return event.relative_humidity;
}