#ifndef INTAKESYSTEM_H_
#define INTAKESYSTEM_H_

#include <Relay.h>

#include "RobotSystem.h"

class InputMethod;
class Jaguar;

class IntakeSystem: public RobotSystem {
private:
	Jaguar* motor;
	Relay* lift;
	InputMethod* inputMethod;
	bool isToggled,catchToggle;
public:
	IntakeSystem();
	virtual ~IntakeSystem();
	virtual void init(Environment* env);
	virtual void run();
	virtual void intake(InputMethod* input);
	virtual void setMotor(double speed);
	virtual void open();
	virtual void close();
};

#endif /* INTAKESYSTEM_H_ */
