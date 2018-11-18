#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype
{
  public:
    /*
     * Default Constructor
     *
     */
    Prototype();

    /* Constructor which takes in the following values
     *
     * param: buttonPin
     *        The pin that the button used to start the program is connected to
     *
     * param: emergencyButtonPin
     *        The pin used as an emergency stop
     *
     * param: ledPin
     *        The pin that the LED is connected to which is activated when the button is pressed to start
     *
     * param: intakeSolenoidPin
     *        The pin which, when activated, should enable air to enter into the vest
     *
     * param: outtakeSolenoidPin
     *        The pin which, when activated, should enable air to exit the vest. This should only be activated
     *        when it is determined if the person is upright and ok and/or the psi has exceeded 6 psi
     *
     * param: pressureSensorPin
     *        The pin which the pressure sensor is connected to. This ensures the pressure in the vest does not surpass 6 psi
     *        As that was determined to be the safety number and therefore upperlimit.
     *
     */
    Prototype(int buttonPin, int emergencyButtonPin, int ledPin, int intakeSolenoidPin, int outtakeSolenoidPin, int pressureSensorPin);
    
    /*
     * The main entry point of the class. Contains the logic which determines if the button has been pressed, and if it has, starts putting air
     * into the vest.
     *
     * When the psi exceeds 6 psi or if it is determined if the user is ok, it will start releasing air as well as turning off the LED.
     *
     */
    void ControlLoop();
    
  private:
    int buttonPin;  // The pin the button is connected to
    int emergencyButtonPin; // The pin used to immediately stop the vest
    int ledPin; // The pin the LED is connected to
    int isButtonPushed; // Internal bool used to determine if the button has been pressed or not
    
    int intakeSolenoidPin;  // The pin the intake solenoid is connected to
    int outtakeSolenoidPin; // The pin the outtake solenoid is connected to
    
    int isIntakeOpen; // Bool used to determine if the intake solenoid has been activated or not
    int isOuttakeOpen;  // Bool used to determine if the outtake solenoid has been activated or not
    
    int pressureSensorPin;  // The pin the pressure sensor is connected to
    
    /*
     * Used to read the value from the pressure sensor
     *
     * returns: The value of the pressure sensor
     *
     */
    int ReadPressureSensor();
    
    /*
     * Used to reset the state of the vest.
     *    Called when the emergency stop button has been pressed
     *
     */
    void ResetState();
};

#endif