#ifndef SHOOTERSYSTEM_H_
#define SHOOTERSYSTEM_H_


#include "RobotSystem.h"
#include "../custom/MultiMotor.h"

#include <Timer.h>
#include <Solenoid.h>

class Relay;
class Victor;
class InputMethod;

class ShooterSystem: public RobotSystem {
private:
	MultiMotor* motor;
	Solenoid* pneumatic;
	InputMethod* inputMethod;
	Timer timer;
	bool isToggled,catchToggle, shooting, shootPressed, manualShooting;
public:
	ShooterSystem();
	virtual ~ShooterSystem();
	virtual void init(Environment* environment);
	virtual void run();
	virtual void shoot(InputMethod* input);
	virtual void open();
	virtual void close();
	virtual void setMotor(double speed);
};

#endif /* SHOOTERSYSTEM_H_ */
