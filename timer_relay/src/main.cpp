#include <Arduino.h>
#include "dht.h"
#include "wemos_d1.h"

const int relayPin = D3;
const int ledPin = LED_BUILTIN;
const int dhtPin = D12;

const int HOUR = 6000;

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup()
{
    pinMode(relayPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
     
    Serial.begin(9600);

    dht.begin();
}

void loop()
{
    Serial.print("temperature:");
    Serial.print(temperature(dht));
    Serial.print(" humidity:");
    Serial.print(humidity(dht));
    Serial.println();

    if (humidity(dht) < 40) {
        digitalWrite(relayPin, HIGH);
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(relayPin, LOW);
        digitalWrite(ledPin, LOW);
    }

    delay(HOUR);
}