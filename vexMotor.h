/****************************************************************
* Core header file for all the various vexMotor functions.
* 
* 22 Dec 2014- Brian Huang, SparkFun Electronics
* 
* Code developed in Arduino 1.0.6
/***************************************************************/

#ifndef vexMotor_h
#define vexMotor_h

#include <Arduino.h>
#include <Servo.h>

// The VEX Motor Controller 29 uses a pulse width between 1000 uS and
// 2000 uS for full speed fwd and rev. 1500 uS is neutral. The signal
// is a standard 50 Hz PWM Servo Signal - so we can use the standard
// servo library in Arduino.
//
// http://www.vexrobotics.com/wiki/Motor_Controller_29

class vexMotor
{
  public:
    vexMotor();      // Constructor. 
	void attach(int pin);   // attaches / sets up the motor on a pin
	void detach(); 			// detach / releases the pin
    void write(int power);  // drive in direction given by sign, at speed given by the
                            //  magnitude of the parameter. Pos. values CW, Neg. values CCW
    
	// default MAX and MIN are +255 to -255. Change these limits with setMax() and setMin()
    void setFullSpeedCW(int max);
    void setFullSpeedCCW(int min);
	int getFullSpeedCW();
	int getFullSpeedCCW();
	
	// set a deadBand limit for the motor. i.e. the abs(power) must be greater than the deadBand to
	// drive the motor.
	void setDeadBand(int deadBand);    // sets the deadBand limit on the motor
    int getDeadBand();
	// often times the zero point of a motor is not exactly at 0. Use this to reset the zero point.
	void setZeroPoint(int zeroPoint);  // sets the zeroPoint
	int getZeroPoint();
	void setMinPulse(int minPulse);    // sets the min pulse width
	void setMaxPulse(int maxPulse);    // sets the max pulse width
	void setNeutralPulse(int neutralPulse);  // sets the zero pulse width
	
	int getMinPulse();    // returns the min pulse width
	int getMaxPulse();    // returns the max pulse width
	int getNeutralPulse();   // returns the zero pulse width

	
	// private variables and objects used in this class.
	
	private:
	Servo _myServo;
	uint8_t _pin;
	int _maxPulse;
	int _minPulse;
	int _neutralPulse;
	int _fullSpeedCW;
	int _fullSpeedCCW;
	int _deadBand;			// 
	int _zeroPoint;			// sets the zeroPoint 
};
#endif