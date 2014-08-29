#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "systems/WheelSystem.h"
#include "systems/IntakeSystem.h"
#include "systems/ShooterSystem.h"
#include "input/InputMethod.h"

#include <RobotBase.h>

class Environment {
private:
	RobotBase* robot;
	InputMethod* input;
	IntakeSystem* intake;
	ShooterSystem* shooter;
	WheelSystem* wheels;
public:
	Environment(RobotBase* bot);
	Environment();
	virtual ~Environment();
	virtual bool isAutonomous();
	virtual bool isOperatorControl();
	virtual InputMethod* getInput();
	virtual IntakeSystem* getIntakeSystem();
	virtual ShooterSystem* getShooterSystem();
	virtual WheelSystem* getWheelSystem();
};

#endif /* ENVIRONMENT_H */
