#include "Prototype.h"

Prototype::Prototype(
  int buttonPin,
  int emergencyButtonPin,
  int ledPin,
  int intakeSolenoidPin,
  int outtakeSolenoidPin,
  int pressureSensorPin)
{
  this->buttonPin = buttonPin;
  this->emergencyButtonPin = emergencyButtonPin;
  this->ledPin = ledPin;
  
  this->isButtonPushed = 0;
  
  this->intakeSolenoidPin = intakeSolenoidPin;
  this->outtakeSolenoidPin = outtakeSolenoidPin;
  
  this->isIntakeOpen = 0;
  this->isOuttakeOpen = 0;
  
  this->pressureSensorPin = pressureSensorPin;
  
  pinMode(this->ledPin, OUTPUT);
  pinMode(this->buttonPin, INPUT);
  pinMode(this->emergencyButtonPin, INPUT);
  
  pinMode(this->intakeSolenoidPin, OUTPUT);
  pinMode(this->outtakeSolenoidPin, OUTPUT);
}

void Prototype::ControlLoop()
{
  // Determine if the button is pressed
  if (!isButtonPushed)
  {
    // Button has not been pushed yet, keep polling until it is pressed
    int buttonState = digitalRead(this->buttonPin);
    
    if (buttonState == HIGH)
    {
      // Button has been pushed, want to start sending air into the vest
      this->isButtonPushed = 1;
      digitalWrite(this->ledPin, HIGH);
    }
  }
  else
  {
    // Determine if emergency stop was hit
    int emergencyButtonState = digitalRead(this->emergencyButtonPin);
    
    if (emergencyButtonState == HIGH)
    {
      // Want to stop and reset the state of the vest
      this->ResetState();
      return;
    }
    
    // Determine if the Intake is open, if not open it as it means the button was just hit
    if (!this->isIntakeOpen && !this->isOuttakeOpen)
    {
      digitalWrite(this->intakeSolenoidPin, HIGH);
      this->isIntakeOpen = 1;
      return;
    }
    
    // Determine if the pressure has surpassed 6 psi, if so close intake, open outtake and wait until it drops
    if (!this->isOuttakeOpen && this->ReadPressureSensor() > 6)
    {
      // Close the intake
      this->isIntakeOpen = 0;
      digitalWrite(this->intakeSolenoidPin, LOW);
      
      // Open the outtake
      this->isOuttakeOpen = 1;
      digitalWrite(this->outtakeSolenoidPin, HIGH);
      
      // Turn off the LED
      digitalWrite(this->ledPin, LOW);
      return;
    }
    
    // TODO: Could balance better when to open the intake and close the outake
  }
}

int Prototype::ReadPressureSensor()
{
  int sensorValue = analogRead(this->pressureSensorPin);
  delay(2);
  sensorValue = analogRead(this->pressureSensorPin);
  
  // TODO: Determine what this sensor value looks like
  return sensorValue;
}

void Prototype::ResetState()
{
  this->isButtonPushed = 0;
  digitalWrite(this->ledPin, LOW);
  
  digitalWrite(this->intakeSolenoidPin, LOW);
  digitalWrite(this->outtakeSolenoidPin, LOW);
  this->isIntakeOpen = 0;
  this->isOuttakeOpen = 1;
}