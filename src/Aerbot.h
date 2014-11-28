#ifndef AERBOT_H_
#define AERBOT_H_

#include <IterativeRobot.h>

#include "Environment.h"

class Executer;

class Aerbot : public IterativeRobot{
private:
	Environment* environment;
	Executer* executer;
public:
	Aerbot();
	virtual ~Aerbot();
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};

#endif /* AERBOT_H_ */
