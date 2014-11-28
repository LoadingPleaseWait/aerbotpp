#ifndef AUTONOMOUSEXECUTER_H_
#define AUTONOMOUSEXECUTER_H_

#include <Timer.h>

#include "Executer.h"

class AutonomousExecuter: public Executer {
private:
	Environment* environment;
	bool started;
	Timer timer;
public:
	AutonomousExecuter();
	AutonomousExecuter(Environment* env);
	virtual ~AutonomousExecuter();
	virtual void init(Environment* env);
	virtual void execute();
};

#endif /* AUTONOMOUSEXECUTER_H_ */
