#include <Arduino.h>
#include "wemos_d1.h"

const int RELAY = D3;
const int DELAY_DURATION = 1000;

void turnOff();
void turnOn();

void setup()
{
    Serial.begin(9600);

    pinMode(RELAY, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    turnOn();
    delay(DELAY_DURATION);

    turnOff();
    delay(DELAY_DURATION);
}

void turnOff()
{
    digitalWrite(RELAY, LOW);
    digitalWrite(LED_BUILTIN, LOW);
}

void turnOn()
{
    digitalWrite(RELAY, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
}