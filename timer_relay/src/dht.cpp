#include "dht.h"

DhtClass::DhtClass() {
    DHT_Unified dht(DHTPIN, DHTTYPE);
    this->dhtModule = &dht;
}

void DhtClass::begin() {
    this->dhtModule->begin();
}

float DhtClass::humidity() {
    sensors_event_t event;
    (this->dhtModule)->humidity().getEvent(&event);
    return event.temperature;
}

float DhtClass::temperature() {
    sensors_event_t event;
    (this->dhtModule)->temperature().getEvent(&event);
    return event.relative_humidity;
}

DHT_Unified* DhtClass::dht() {
    return (this->dhtModule);
}