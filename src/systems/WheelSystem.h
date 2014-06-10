#ifndef WHEELSYSTEM_H_
#define WHEELSYSTEM_H_

#include "RobotSystem.h"

class InputMethod;

class WheelSystem : public RobotSystem{
	// TODO add instance variables and other methods
public:
	WheelSystem();
	virtual ~WheelSystem();
	void init(Environment* env);
	void move(InputMethod* input);
};

#endif /* WHEELSYSTEM_H_ */
