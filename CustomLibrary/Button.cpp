#include <Arduino.h>
#include "Button.h"

Button::Button()
{
}

Button::Button(int buttonPin)
{
    this->buttonPin = buttonPin;

    pinMode(this->buttonPin, INPUT);
}

int Button::IsButtonPressed()
{
    int buttonState = digitalRead(this->buttonPin);

    return buttonState == HIGH;
}

Button& Button::operator=(Button other)
{
    this->buttonPin = other.buttonPin;
    return *this;
}