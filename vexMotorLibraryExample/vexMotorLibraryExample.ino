/* vexMotorLibraryExample.ino
 
 Upload this program to your Arduino and open up the Serial Monitor
 to manually control / specify the speed of your servo motor.
 
 This example exercises all of the methods and properties that are
 used in the vexMotor class. vexMotor uses the Servo library. You must 
 include both vexMotor.h and Servo.h.
 
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

#include <vexMotor.h> // includes the vexMotor library (must also include Servo.h)
#include <Servo.h>    // servo library -- vexMotor relies on the Servo library

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
  Serial.println("Choose an option:");  // Print a blank line
  Serial.println(" 1) Set Speed");
  Serial.println(" 2) Set Zero / Neutral Point");
  Serial.println(" 3) Set DeadBand");
  Serial.println(" 4) Set Full Speed CCW");
  Serial.println(" 5) Set Full Speed CW");
  Serial.println(" 6) Set Min Pulse Width");
  Serial.println(" 7) Set Neutral Pulse Width");
  Serial.println(" 8) Set Max Pulse Width");

  Serial.println("*-------------------------------------*");  // Print a blank line

  // Holding loop until an input is read.
  while (Serial.available() == 0)
  {
  }

  // Read in value from Serial Monitor
  inputValue = Serial.parseInt();

  switch(inputValue)
  {
  case 1: // set Speed
    Serial.print("Enter in a value for the Motor Speed (");
    Serial.print(myVexMotor1.getFullSpeedCCW());
    Serial.print(" to +");
    Serial.print(myVexMotor1.getFullSpeedCW());
    Serial.println(")");

    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Motor Speed to: ");
    Serial.println(inputValue);
    myVexMotor1.write(inputValue);
    break;
  case 2:  // set Zero
    Serial.print("Motor Zero Point is currently set to: ");
    Serial.println(myVexMotor1.getZeroPoint());
    Serial.println("Enter in a value for the Motor Zero Point:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Motor Zero Point to: ");
    Serial.println(inputValue);
    myVexMotor1.setZeroPoint(inputValue);
    break;
  case 3:  // set deadBand
    Serial.print("Motor Dead Band is currently set to: ");
    Serial.println(myVexMotor1.getDeadBand());
    Serial.println("Enter in a value for the Motor Dead Band:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Motor Dead Band to: ");
    Serial.println(inputValue);
    myVexMotor1.setDeadBand(inputValue);
    break;
  case 4:  // set full Speed CCW
    Serial.print("Motor Full Speed CCW is currently set to: ");
    Serial.println(myVexMotor1.getFullSpeedCCW());
    Serial.println("Enter in a value for Full Speed CCW:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Motor Full Speed CCW to: ");
    Serial.println(inputValue);
    myVexMotor1.setFullSpeedCCW(inputValue);
    break;
  case 5:  // set Full Speed CW
    Serial.print("Motor Full Speed CW is currently set to: ");
    Serial.println(myVexMotor1.getFullSpeedCW());
    Serial.println("Enter in a value for Full Speed CW:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Motor Full Speed CW to: ");
    Serial.println(inputValue);
    myVexMotor1.setFullSpeedCW(inputValue);
    break;
  case 6:  // set min pulse width
    Serial.print("Minimum Pulse Width is currently set to: ");
    Serial.println(myVexMotor1.getMinPulse());
    Serial.println("Enter in a value for Minimum Pulse Width:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Minimum Pulse Width to: ");
    Serial.println(inputValue);
    myVexMotor1.setMinPulse(inputValue);
    break;    
  case 7:  // set neutral pulse width
    Serial.print("Neutral Pulse Width is currently set to: ");
    Serial.println(myVexMotor1.getNeutralPulse());
    Serial.println("Enter in a value for Neutral Pulse Width:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Neutral Pulse Width to: ");
    Serial.println(inputValue);
    myVexMotor1.setNeutralPulse(inputValue);
    break;    
  case 8:  // set max pulse width
    Serial.print("Maximum Pulse Width is currently set to: ");
    Serial.println(myVexMotor1.getMaxPulse());
    Serial.println("Enter in a value for Maximum Pulse Width:");
    while (Serial.available() == 0)
    {
    } 
    inputValue = Serial.parseInt();
    Serial.print("Setting Maximum Pulse Width to: ");
    Serial.println(inputValue);
    myVexMotor1.setMaxPulse(inputValue);
    break; 
    
  default:
    Serial.print("Setting Motor Speed to: ");
    Serial.println(inputValue);
    myVexMotor1.write(inputValue);
    break;
  }
  Serial.println();
  Serial.println();
}






