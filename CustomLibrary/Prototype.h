#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "Button.h"
#include "Solenoid.h"
#include "LED.h"

class Prototype
{
  public:

    // Default Constructor
    Prototype();

    // Constructor
    //
    // param: startButton
    //        Button to activate the suit
    //
    // param: startButtonLED
    //        LED to indicate if the start button has been pressed
    //
    // param: emergencyButton
    //        Button to reset the device
    //
    // param: intakeSolenoid
    //        Solenoid to send air into the vest
    //
    // param: outakeSolenoid
    //        Solenoid to send air out of the vest
    Prototype(Button startButton, LED startButtonLED, Button emergencyButton, Solenoid intakeSolenoid, Solenoid outtakeSolenoid);
    
    // Main control looop for the vest
    void ControlLoop();
    
  private:

    Button startButton; // The button to start the soft robotic suit
    LED startButtonLED; // LED to indicate that the start button has been pressed

    int isStartButtonPressed; // int to indicate if it has been started

    Button emergencyButton; // The button to reset the suit

    Solenoid intakeSolenoid;  // The solenoid to send air into the vest

    Solenoid outtakeSolenoid; // The solenoid to send air out of the vest
    
    // Resets the state of the suit
    void ResetState();
};

#endif