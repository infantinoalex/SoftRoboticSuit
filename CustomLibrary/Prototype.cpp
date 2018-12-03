#include <Arduino.h>
#include "Prototype.h"

Prototype::Prototype()
{
}

Prototype::Prototype(Button startButton, LED startButtonLED, Solenoid solenoid, MPU mpu)
{
  this->startButton = startButton;
  this->startButtonLED = startButtonLED;

  this->solenoid = solenoid;
  this->MPU = mpu;

  this->isStartButtonPressed = 0;
}

void Prototype::ControlLoop()
{
  // Determine if the button is pressed
  if (this->startButton.IsButtonPressed())
  {
    this->isStartButtonPressed = 1;
    this->startButtonLED.TurnOnLED();
  }
  else if (this->isStartButtonPressed)
  {

    this->solenoid.OpenSolenoid();
    delay(2000);
    this->startButtonLED.TurnOffLED();
    this->solenoid.CloseSolenoid();
  }
}

void Prototype::ResetState()
{
  this->isStartButtonPressed = 0;
  this->startButtonLED.TurnOffLED();

  this->solenoid.OpenSolenoid();
}
