#ifndef MOVEMENTLISTENER_H_
#define MOVEMENTLISTENER_H_

#include "Listener.h"

class MovementListener: public Listener {
private:
	Environment* environment;
public:
	MovementListener();
	virtual ~MovementListener();
	void init(Environment* env);
	bool shouldExecute();
	void execute();
};

#endif /* MOVEMENTLISTENER_H_ */
