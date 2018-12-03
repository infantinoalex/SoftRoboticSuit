#ifndef SOLENOID_H
#define SOLENOID_H

#include "LED.h"

class Solenoid
{
    public:

        // Default Constructor
        Solenoid();

        // Constructor
        //
        // param: solenoidPin
        //          The pin that the solenoid is connected to
        Solenoid(int solenoidPin);

        // Opens up the intake flow for the solenoid
        void OpenSolenoid();

        // Opens up the outtake flow for the solenoid
        void CloseSolenoid();

        // Determine if the solenoid is open or not
        int IsOpen();

        // Overloads the = operator
        Solenoid& operator=(Solenoid other);

    private:

        int solenoidPin;    // The pin the solenoid is connected to

        int isOpen; // Used to determine if the solenoid is open
};

#endif
