#ifndef INTAKELISTENER_H_
#define INTAKELISTENER_H_

#include "Listener.h"

class IntakeListener: public Listener {
private:
	Environment* environment;
public:
	IntakeListener();
	virtual ~IntakeListener();
	void init(Environment* env);
	bool shouldExecute();
	void execute();
};

#endif /* INTAKELISTENER_H_ */
