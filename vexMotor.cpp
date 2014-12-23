/*******************************************************************
* Main CPP for vexMotor library. Uses the Servo library and scales 
* an input power (-255 to +255) to a pulse width for the VEX motor 
* controller. 
*
* Positive values rotate the motor CW, negative balues rotate the 
* motor CCW.
*
* 22 Dec 2014 - Brian Huang, SparkFun Electronics
* Code developed in Arduino 1.0.6
/******************************************************************/

#include "vexMotor.h"
#include <avr/interrupt.h>
#include <Arduino.h>

vexMotor::vexMotor()
{
	_zeroPoint = 0;  // default zeroPoint
	_deadBand = 5;      // default deadBand
	_fullSpeedCCW = -255;
	_fullSpeedCW = 255;
	_maxPulse = 2000;
	_neutralPulse = 1500;
	_minPulse = 1000;
}

void vexMotor::attach(int pin)
{
	_myServo.attach(pin);
	_pin = pin;
}

void vexMotor::detach()
{
	_myServo.detach();
}

void vexMotor::write(int power)
{	
	// VEX Motor Controller spins CW for pulse widths less than 1500 uS and
	// CCW for pulse widths greater than 1500. map() scales the power to a
	// pulse width.
	int pulseWidth;
	
	// if it's greater than _deadBand -- then it spinning in the CW
	if ((power - _zeroPoint) > _deadBand)
	{
		pulseWidth = map(power, _zeroPoint, _fullSpeedCW, _neutralPulse, _minPulse);	
		_myServo.writeMicroseconds(pulseWidth);
		}
	else if ((power - _zeroPoint) < -_deadBand)
	{
		pulseWidth = map(power, _fullSpeedCCW, _zeroPoint, _maxPulse, _neutralPulse);	
		_myServo.writeMicroseconds(pulseWidth);
	}
	else
	{
		_myServo.writeMicroseconds(_neutralPulse);
	}
}

void vexMotor::setZeroPoint(int zeroPoint)  
{
	if (zeroPoint >= _fullSpeedCW)
	{
		_zeroPoint = _fullSpeedCW;
	}
	else if (zeroPoint <= _fullSpeedCCW)
	{
		_zeroPoint = _fullSpeedCCW;
	}
	else
	{
		_zeroPoint = zeroPoint;
	}
}

int vexMotor::getZeroPoint() 
{
	return _zeroPoint;
}

void vexMotor::setDeadBand(int deadBand)
{
	_deadBand = deadBand;
} 

int vexMotor::getDeadBand()
{
	return _deadBand;
}

void vexMotor::setFullSpeedCW(int fullSpeedCW)
{
	if(fullSpeedCW <= _zeroPoint)
	{
		_fullSpeedCW = _zeroPoint;
	}
	else
		_fullSpeedCW = fullSpeedCW;
}

void vexMotor::setFullSpeedCCW(int fullSpeedCCW)
{
	if(fullSpeedCCW >= _zeroPoint)
	{
		_fullSpeedCCW = _zeroPoint;
	}
	else
		_fullSpeedCCW = fullSpeedCCW;
}

int vexMotor::getFullSpeedCW() 
{
	return _fullSpeedCW;
}
int vexMotor::getFullSpeedCCW() 
{
	return _fullSpeedCCW;
}

void vexMotor::setMaxPulse(int maxPulse)
{
	_maxPulse = maxPulse;
}

void vexMotor::setMinPulse(int minPulse)
{
	_minPulse = minPulse;
}


void vexMotor::setNeutralPulse(int neutralPulse)
{
	_neutralPulse = neutralPulse;
}


int vexMotor::getMaxPulse()
{
	return _maxPulse;
}

int vexMotor::getMinPulse()
{
	return _minPulse;
}


int vexMotor::getNeutralPulse()
{
	return _neutralPulse;
}
