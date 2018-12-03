#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "Button.h"
#include "Solenoid.h"
#include "LED.h"
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"


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
    // param: solenoid
    //        Solenoid to send air into the vest
    Prototype(Button startButton, LED startButtonLED, Solenoid solenoid);
    
    // Main control looop for the vest
    void ControlLoop();
    
  private:

    Button startButton; // The button to start the soft robotic suit
    LED startButtonLED; // LED to indicate that the start button has been pressed

    int isStartButtonPressed; // int to indicate if it has been started

    Solenoid solenoid;  // The solenoid to send air into the vest

    MPU6050 MPU;  // The accelerometer

    // Resets the state of the suit
    void ResetState();
};

#endif
