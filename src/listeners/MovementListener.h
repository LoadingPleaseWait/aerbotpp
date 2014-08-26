#ifndef MOVEMENTLISTENER_H_
#define MOVEMENTLISTENER_H_

#include "Listener.h"

class MovementListener: public Listener {
private:
	Environment* environment;
public:
	MovementListener();
	virtual ~MovementListener();
	virtual void init(Environment* env);
	virtual bool shouldExecute();
	virtual void execute();
};

#endif /* MOVEMENTLISTENER_H_ */
