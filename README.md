vexMotor
========

vexMotor Arduino library. This library simplifies the interface between Arduino and the VEX motors through the VEX Motor Controller 29.

###class vexMotor

###Methods:

	void attach(int pin);   // attaches / sets up the motor on a pin
	void detach(); 			// detach / releases the pin
    void write(int power);  // drive in direction given by sign, at speed given by the
                            //  magnitude of the parameter. Pos. values CW, Neg. values CCW
    
	// default FullSpeedCW and FullSpeed CCW are +255 to -255. Change these limits with setFullSpeedCW() and setFullSpeedCCW()
    void setFullSpeedCW(int max);
    void setFullSpeedCCW(int min);
	int getFullSpeedCW();		// returns the current fullSpeedCW setting
	int getFullSpeedCCW();		// returns the current fullSpeedCCW setting
	
	// set a deadBand limit for the motor. i.e. the abs(power) must be greater than the deadBand to
	// drive the motor.
	void setDeadBand(int deadBand);    // sets the deadBand limit on the motor
    int getDeadBand();				   // returns the deadBand setting

	// often times the zero point of a motor is not exactly at 0. Use this to reset the zero point.
	void setZeroPoint(int zeroPoint);  // sets the zeroPoint
	int getZeroPoint();
	
	// sets/returns the pulse Width settings for the motor -- for VEX Motors, these are 1000 uS to 2000 uS with 1500 uS being neutral
	void setMinPulse(int minPulse);    // sets the min pulse width
	void setMaxPulse(int maxPulse);    // sets the max pulse width
	void setNeutralPulse(int neutralPulse);  // sets the zero pulse width
	
	int getMinPulse();    // returns the min pulse width
	int getMaxPulse();    // returns the max pulse width
	int getNeutralPulse();   // returns the zero pulse width


Click [here](https://github.com/sparkfun/vexMotor/archive/master.zip) to download a zip file. Unzip this to a folder called vexMotor in the \arduino\libraries folder in your documents. You must re-name the folder vexMotor (remove the "-master") from the folder name).
