#include <Arduino.h>
#include "Prototype.h"

Prototype::Prototype()
{
}

Prototype::Prototype(Button startButton, LED startButtonLED, Button emergencyButton, Solenoid intakeSolenoid, Solenoid outtakeSolenoid)
{
  this->startButton = startButton;
  this->startButtonLED = startButtonLED;

  this->emergencyButton = emergencyButton;

  this->intakeSolenoid = intakeSolenoid;

  this->outtakeSolenoid = outtakeSolenoid;

  this->isStartButtonPressed = 0;

  this->outtakeSolenoid.OpenSolenoid();
}

void Prototype::ControlLoop()
{
  // Determine if the button is pressed
  if (!this->isStartButtonPressed)
  {
    if (this->startButton.IsButtonPressed())
    {
      this->isStartButtonPressed = 1;
      this->startButtonLED.TurnOnLED();
    }
  }
  else
  {
    if (this->emergencyButton.IsButtonPressed())
    {
      this->ResetState();
      return;
    }
    
    if (!this->intakeSolenoid.IsOpen() && !this->outtakeSolenoid.IsOpen())
    {
        this->intakeSolenoid.OpenSolenoid();
        this->outtakeSolenoid.CloseSolenoid();
        return;
    }
  }
}

void Prototype::ResetState()
{
  this->isStartButtonPressed = 0;
  this->startButtonLED.TurnOffLED();

  this->intakeSolenoid.CloseSolenoid();
  this->outtakeSolenoid.OpenSolenoid();
}