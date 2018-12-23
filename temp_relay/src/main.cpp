#include <Arduino.h>
#include "dht.h"
#include "wemos_d1.h"

const int relayPin = D3;
const int ledPin = LED_BUILTIN;
const int dhtPin = D12;

const int HALF_HOUR = 30 * 60 * 1000;

DhtClass *dhtClass = new DhtClass(dhtPin);

void setup()
{
    pinMode(relayPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
     
    Serial.begin(9600);

    dhtClass->begin();
}

void loop()
{
    float temperature = dhtClass->temperature();
    float humidity = dhtClass->humidity();

    Serial.print("temperature:");
    Serial.print(temperature);
    Serial.print(" humidity:");
    Serial.print(humidity);
    Serial.println();

    if (humidity < 40) {
        digitalWrite(relayPin, HIGH);
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(relayPin, LOW);
        digitalWrite(ledPin, LOW);
    }

    delay(HALF_HOUR);
}