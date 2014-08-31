#ifndef XBOXINPUT_H_
#define XBOXINPUT_H_

#include <Joystick.h>

#include "InputMethod.h"

#define BUTTON_A 1
#define BUTTON_B 2
#define BUTTON_X 3
#define BUTTON_Y 4
#define LEFT_BUMPER 5
#define RIGHT_BUMPER 6
#define BUTTON_BACK 7
#define BUTTON_START 8
#define LEFT_STICK 9
#define RIGHT_STICK 10
#define LEFT_STICK_X 1
#define LEFT_STICK_Y 2
#define TRIGGERS 3
#define RIGHT_STICK_X 4
#define RIGHT_STICK_Y 5
#define DIRECTIONAL_PAD 6

class XboxInput : public InputMethod{
private:
	Joystick controller;
public:
	XboxInput();
	virtual ~XboxInput();
	double getLeftX();
	double getRightX();
	double getLeftY();
	double getRightY();
	bool shift();
	bool catchBall();
	bool shoot();
	bool manualShoot();
	bool intake();
	bool outtake();
	bool intakeToggle();
	bool intakeLift();
	bool directionToggle();

};

#endif /* XBOXINPUT_H_ */
