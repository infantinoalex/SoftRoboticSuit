#include <Arduino.h>
#include "Solenoid.h"

Solenoid::Solenoid()
{
}

Solenoid::Solenoid(int solenoidPin)
{
    this->solenoidPin = solenoidPin;
    pinMode(this->solenoidPin, OUTPUT);

    this->isOpen = 0;
}

void Solenoid::OpenSolenoid()
{
    digitalWrite(this->solenoidPin, HIGH);
    this->isOpen = 1;
}

void Solenoid::CloseSolenoid()
{
    digitalWrite(this->solenoidPin, LOW);
    this->isOpen = 0;
}

int Solenoid::IsOpen()
{
    return this->isOpen;
}

Solenoid& Solenoid::operator=(Solenoid other)
{
    this->solenoidPin = other.solenoidPin;
    this->isOpen = other.IsOpen();
    return *this;
}
