#ifndef PARTNERXBOXINPUT_H_
#define PARTNERXBOXINPUT_H_

#include "XboxInput.h"

class PartnerXboxInput : public InputMethod{
private:
	Joystick driver,shooter;
public:
	PartnerXboxInput();
	virtual ~PartnerXboxInput();
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

#endif /* PARTNERXBOXINPUT_H_ */
