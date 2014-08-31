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
	void init(Environment* env);
	bool shouldExecute();
	void execute();
};

#endif /* SHOOTERLISTENER_H_ */
