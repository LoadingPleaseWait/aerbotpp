#ifndef AERBOT_H_
#define AERBOT_H_

#include <IterativeRobot.h>

#include "Environment.h"
#include "Executer.h"

class Aerbot : public IterativeRobot{
private:
	Environment* environment;
	Executer* executer;
public:
	Aerbot();
	virtual ~Aerbot();
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
};

#endif /* AERBOT_H_ */
