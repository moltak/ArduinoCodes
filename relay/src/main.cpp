#include <Arduino.h>
#include "wemos_d1.h"

const int relayPin = D3;
const int ledPin = LED_BUILTIN;

const int DELAY_DURATION = 1000;

void setup()
{
    pinMode(relayPin, OUTPUT);
    pinMode(ledPin, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    digitalWrite(relayPin, HIGH);
    digitalWrite(ledPin, HIGH);

    delay(10000);

    digitalWrite(relayPin, LOW);
    digitalWrite(ledPin, LOW);

    delay(DELAY_DURATION);
}