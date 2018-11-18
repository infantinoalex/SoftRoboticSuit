/*
  Currently just sets up the accelerometer.
  Code taken directly from: https://playground.arduino.cc/Main/MPU-6050#short
  
  The I2C-address depends on the AD0 pin of the sensor.
  If it is connected to ground, the address is 0x68.
  If it is connected to VLOGIC (+3.3V) it is 0x69.
  There are a few sensor boards with the MPU-6050 sensor already soldered on it.
  Some of those boards have a pull-down resistor at AD0 (address = 0x68), others have a pull-up resistor (address = 0x69).

  Search in the sketch for "MPU6050_I2C_ADDRESS" and set that to your own I2C address.
  A i2c_scanner can be used to check if the device is connected to the i2c bus.
  The acceleration and gyro values of the sketch are raw values, which are not yet compensated for offset. 
  The very first acceleration and gyro values after power up are sometimes not valid.
  
  Need to actually convert the data to usable values.
  https://playground.arduino.cc/Main/MPU-6050#info
  
  There are some links to actually useful code there that I should be able to use

*/

#include <Wire.h>
#include <Prototype.h>

int buttonPin;
int emergencyButtonPin;
int ledPin;
int intakeSolenoidPin;
int outtakeSolenoidPin;
int pressureSensorPin;

Prototype prototype;

/* TODO: Contains code for the accelerometer
// 12C address of the MPU-6050
const int MPUAddress = 0x68;
int16_t xAcceleration, yAcceleration, zAcceleration;
*/

void setup() 
{
  prototype = Prototype(buttonPin, emergencyButtonPin, ledPin, intakeSolenoidPin, outtakeSolenoidPin, pressureSensorPin);
  
  /* TODO: Contains setup for the accelerometer. Need to determine how to incorporate into code.
  Wire.begin();
  Wire.beginTransmission(MPUAddress);
  
  // PWR_MGMT_1 register
  Wire.write(0x6B);
  
  // Wakes up the MPU-6050
  Wire.write(0);
  
  Wire.endTransmission(true);
  
  Serial.begin(9600);
  */
}

void loop() 
{
  prototype.ControlLoop();
  /* TODO: Contains code to listen to the accelerometer. Need to determine how to incorporate into code
  Wire.beginTransmission(MPUAddress);
  
  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.write(0x3B);
  Wire.endTransmission(false);
  
  // request a total of 14 registers
  Wire.requestFrom(MPUAddress, 14, true);
  
  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  xAcceleration = Wire.read() << 8 | Wire.read();
  
  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  yAcceleration = Wire.read() << 8 | Wire.read();
  
  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  zAcceleration = Wire.read() << 8 | Wire.read();

  Serial.print("X Accleration = ");
  Serial.print(xAcceleration);
  
  Serial.print(" | Y Acceleration = ");
  Serial.print(yAcceleration);
  
  Serial.print(" | Z Accleration = "); 
  Serial.print(zAcceleration);
  
  delay(333);
  */
}
