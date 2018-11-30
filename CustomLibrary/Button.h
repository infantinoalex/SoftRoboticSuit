#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    public:

        // Default Constructor
        Button();

        // Constructor
        //
        // param: buttonPin
        //          The pin that the button is connected to
        Button(int buttonPin);

        // Used to determine if the button has been pressed
        int IsButtonPressed();

        // Overloads the = operator
        Button& operator=(Button other);

    private:
    
        int buttonPin;  // The pin the button is connected to
};

#endif