#ifndef TELEOPEXECUTER_H_
#define TELEOPEXECUTER_H_

#include <vector>
#include "Executer.h"
#include "systems/RobotSystem.h"

class TeleopExecuter: public Executer{
private:
	std::vector<RobotSystem*> systems;
public:
	TeleopExecuter();
	TeleopExecuter(Environment* env);
	virtual ~TeleopExecuter();
	virtual void init(Environment* env);
	virtual void execute();
};

#endif
