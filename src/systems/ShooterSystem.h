/*
 * 
 */

#ifndef SHOOTERSYSTEM_H_
#define SHOOTERSYSTEM_H_

#include "RobotSystem.h"

class Relay;
class Victor;
class InputMethod;

class ShooterSystem: public RobotSystem {
private:
	Victor* motor;
	Relay* pneumatic;
	bool isToggled,catchToggle, shooting, shootPressed;
public:
	ShooterSystem();
	virtual ~ShooterSystem();
	virtual void init(Environment* environment);
	virtual void shoot(InputMethod* input);
	virtual void open();
	virtual void close();
	virtual void setMotor(double speed);
};

#endif /* SHOOTERSYSTEM_H_ */
