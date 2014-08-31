#ifndef PARTNERXBOXINPUT_H_
#define PARTNERXBOXINPUT_H_

#include "XboxInput.h"

class PartnerXboxInput : public InputMethod{
private:
	Joystick driver,shooter;
public:
	PartnerXboxInput();
	virtual ~PartnerXboxInput();
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

#endif /* PARTNERXBOXINPUT_H_ */
