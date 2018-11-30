#include <Arduino.h>
#include "LED.h"

LED::LED()
{
}

LED::LED(int ledPin)
{
    this->ledPin = ledPin;
    pinMode(this->ledPin, OUTPUT);
}

void LED::TurnOnLED()
{
    digitalWrite(this->ledPin, HIGH);
}

void LED::TurnOffLED()
{
    digitalWrite(this->ledPin, LOW);
}

LED& LED::operator=(LED other)
{
    this->ledPin = other.ledPin;
    return *this;
}