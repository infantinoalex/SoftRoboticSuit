#ifndef LED_H
#define LED_H

class LED
{
    public:

        // Default Constructor
        LED();

        // Cosntructor
        //
        // param: ledPin
        //          The pin that the led is connected to
        LED(int ledPin);

        // Turns off the LED
        void TurnOnLED();

        // Turns on the LED
        void TurnOffLED();

        // Overloads the = operator
        LED& operator=(LED other);

    private:
    
        int ledPin; // The pin the LED is connected to
};

#endif