#include <Button.h>
#include <LED.h>
#include <Prototype.h>
#include <Solenoid.h>

int startButtonPin;
int startButtonLEDPin;

int emergencyButtonPin;

int intakeSolenoidPin;
int intakeSolenoidLEDPin;

int outtakeSolenoidPin;
int outtakeSolenoidLEDPin;

Prototype prototype;

void setup() 
{
  Button startButton = Button(startButtonPin);
  LED startButtonLED = LED(startButtonLEDPin);

  Button emergencyButton = Button(emergencyButtonPin);

  LED intakeSolenoidLED = LED(intakeSolenoidLEDPin);
  Solenoid intakeSolenoid = Solenoid(intakeSolenoidPin, intakeSolenoidLED);

  LED outtakeSolenoidLED = LED(outtakeSolenoidLEDPin);
  Solenoid outtakeSolenoid = Solenoid(outtakeSolenoidPin, outtakeSolenoidLED);
  
  prototype = Prototype(startButton,startButtonLED, emergencyButton, intakeSolenoid, outtakeSolenoid);
}

void loop() 
{
  prototype.ControlLoop();
}
