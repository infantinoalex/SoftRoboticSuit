#include <Button.h>
#include <LED.h>
#include <Prototype.h>
#include <Solenoid.h>

int startButtonPin = 2;
int startButtonLEDPin = 5;

int solenoidPin = 9;

Prototype prototype;

void setup() 
{
  Button startButton = Button(startButtonPin);
  LED startButtonLED = LED(startButtonLEDPin);

  Solenoid solenoid = Solenoid(solenoidPin);
  
  prototype = Prototype(startButton, startButtonLED, solenoid);
}

void loop() 
{
  prototype.ControlLoop();
}
