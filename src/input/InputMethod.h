#ifndef INPUTMETHOD_H_
#define INPUTMETHOD_H_

class InputMethod{
public:
	virtual double getLeftX() =0;
	virtual double getRightX() =0;
	virtual double getLeftY() =0;
	virtual double getRightY() =0;
	virtual bool shift() =0;
	virtual bool catchBall() =0;
	virtual bool shoot() =0;
	virtual bool manualShoot() =0;
	virtual bool intake() =0;
	virtual bool outtake() =0;
	virtual bool intakeToggle() =0;
	virtual bool directionToggle() =0;
};

#endif
