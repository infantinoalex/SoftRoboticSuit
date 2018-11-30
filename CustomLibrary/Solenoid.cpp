#include <Arduino.h>
#include "Solenoid.h"

Solenoid::Solenoid()
{
}

Solenoid::Solenoid(int solenoidPin, LED solenoidLED)
{
    this->solenoidPin = solenoidPin;
    pinMode(this->solenoidPin, OUTPUT);

    this->isOpen = 0;

    this->solenoidLED = solenoidLED;
}

void Solenoid::OpenSolenoid()
{
    if (this->isOpen)
    {
        return;
    }

    digitalWrite(this->solenoidPin, HIGH);
    this->solenoidLED.TurnOnLED();
    this->isOpen = 1;
}

void Solenoid::CloseSolenoid()
{
    if (!this->isOpen)
    {
        return;
    }

    digitalWrite(this->solenoidPin, LOW);
    this->solenoidLED.TurnOffLED();
    this->isOpen = 0;
}

int Solenoid::IsOpen()
{
    return this->isOpen;
}

Solenoid& Solenoid::operator=(Solenoid other)
{
    this->solenoidPin = other.solenoidPin;
    this->solenoidLED = other.solenoidLED;
    this->isOpen = other.IsOpen();
    return *this;
}