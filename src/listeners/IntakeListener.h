#ifndef INTAKELISTENER_H_
#define INTAKELISTENER_H_

#include "Listener.h"

class IntakeListener: public Listener {
private:
	Environment* environment;
public:
	IntakeListener();
	virtual ~IntakeListener();
	virtual void init(Environment* env);
	virtual bool shouldExecute();
	virtual void execute();
};

#endif /* INTAKELISTENER_H_ */
