#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <RobotBase.h>

#include "input/PartnerXboxInput.h"
#include "systems/IntakeSystem.h"

class Environment {
private:
	RobotBase* robot;
	InputMethod* input;
	IntakeSystem* intake;
public:
	Environment(RobotBase* bot);
	Environment();
	virtual ~Environment();
	virtual bool isAutonomous();
	virtual bool isOperatorControl();
	virtual InputMethod* getInput();
	virtual IntakeSystem* getIntakeSystem();
};

#endif /* ENVIRONMENT_H_ */
