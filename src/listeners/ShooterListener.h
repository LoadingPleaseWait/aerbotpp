#ifndef SHOOTERLISTENER_H_
#define SHOOTERLISTENER_H_

#include "Listener.h"

class InputMethod;

class ShooterListener : public Listener{
private:
	Environment* environment;
public:
	ShooterListener();
	virtual ~ShooterListener();
	virtual void init(Environment* env);
	virtual bool shouldExecute();
	virtual void execute();
};

#endif /* SHOOTERLISTENER_H_ */
