/* vexMotorTest.ino
 
 Upload this program to your Arduino and open up the Serial Monitor
 to manually control / specify the speed of your servo motor.
 
 Hardware connections:
 =====================
 To connect the standard 2-wire VEX motor 393 to an Arduino requires 
 a Motor Controller 29 module. Connect the wires on the Motor Controller 
 to the Arduino with the following pins:
 
 MOTOR CONTROLLER 29  <-------->  ARDUINO
 ============================================= 
 WHITE (signal)           Digital pin 9
 RED (power)              VIN (Battery Power -- 5V works too, but won't be as strong or fast)
 BLACK (ground)           Ground (GND)
 
 This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
 This code is completely free for any use.
 */

#include <vexMotor.h> // includes the vexMotor library - uses Servo.h
                      // -- do not #include <Servo.h>                     

vexMotor myVexMotor1;  // creates an instance of the vexMotor class
// create an instance for each motor that is connected
// to your device.

void setup()
{
  myVexMotor1.attach(9); // setup / attach the vexMotor onto pin 9
  Serial.begin(9600);    // starts the Serial communication on Arduino
}

void loop()
{
  int inputValue;
  // Print out prompt for user.
  Serial.println("*-------------------------------------*");  // Print a blank line
  Serial.println("* Type a Motor Power (-255 to 255),   *");
  Serial.println("* then click [send] or press [return] *");
  Serial.println("*-------------------------------------*");  // Print a blank line

  // Holding loop until an input is read.
  while (Serial.available() == 0)
  {
  }

  // Read in value from Serial Monitor
  inputValue = Serial.parseInt();

  // Print out a message to let you know that the value was received
  Serial.print("Setting power to: ");
  Serial.print(inputValue);
  Serial.println(".");
  Serial.println();

  // Set the speed of the motor. vexMotor.write() takes an input value from -255 to +255. 
  // -255 is max speed reverse
  myVexMotor1.write(inputValue);
}
