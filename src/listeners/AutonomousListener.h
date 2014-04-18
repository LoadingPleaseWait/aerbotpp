/*
 * 
 */

#ifndef AUTONOMOUSLISTENER_H_
#define AUTONOMOUSLISTENER_H_

#include <Timer.h>

#include "Listener.h"

class AutonomousListener: public Listener {
private:
	Environment* environment;
	bool started;
	Timer timer;
public:
	AutonomousListener();
	virtual ~AutonomousListener();
	virtual void init(Environment* env);
	virtual bool shouldExecute();
	virtual void execute();
};

#endif /* AUTONOMOUSLISTENER_H_ */
