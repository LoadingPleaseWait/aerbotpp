#ifndef XBOXINPUT_H_
#define XBOXINPUT_H_

#include <Joystick.h>

#include "InputMethod.h"

const int BUTTON_A = 1;
const int BUTTON_B = 2;
const int BUTTON_X = 3;
const int BUTTON_Y = 4;
const int LEFT_BUMPER = 5;
const int RIGHT_BUMPER = 6;
const int BUTTON_BACK = 7;
const int BUTTON_START = 8;
const int LEFT_STICK = 9;
const int RIGHT_STICK = 10;
const int LEFT_STICK_X = 1;
const int LEFT_STICK_Y = 2;
const int TRIGGERS = 3;
const int RIGHT_STICK_X = 4;
const int RIGHT_STICK_Y = 5;
const int DIRECTIONAL_PAD = 6;

class XboxInput : public InputMethod{
private:
	Joystick controller;
public:
	XboxInput();
	virtual ~XboxInput();
	virtual double getLeftX();
	virtual double getRightX();
	virtual double getLeftY();
	virtual double getRightY();
	virtual bool shift();
	virtual bool catchBall();
	virtual bool shoot();
	virtual bool manualShoot();
	virtual bool intake();
	virtual bool outtake();
	virtual bool intakeToggle();
	virtual bool intakeLift();
	virtual bool directionToggle();

};

#endif /* XBOXINPUT_H_ */
