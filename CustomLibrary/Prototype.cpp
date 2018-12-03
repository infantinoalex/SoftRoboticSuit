#include <Arduino.h>
#include "Prototype.h"

Prototype::Prototype()
{
}

Prototype::Prototype(Button startButton, LED startButtonLED, Solenoid solenoid)
{
  this->startButton = startButton;
  this->startButtonLED = startButtonLED;

  this->solenoid = solenoid;

  this->isStartButtonPressed = 0;
}

void Prototype::ControlLoop()
{
  // Determine if the button is pressed
  if (this->startButton.IsButtonPressed())
  {
    this->startButtonLED.TurnOnLED();
    this->solenoid.OpenSolenoid();
    delay(2000);
    this->startButtonLED.TurnOffLED();
    this->solenoid.OpenSolenoid();
  }
}

void Prototype::ResetState()
{
  this->isStartButtonPressed = 0;
  this->startButtonLED.TurnOffLED();

  this->solenoid.OpenSolenoid();
}
