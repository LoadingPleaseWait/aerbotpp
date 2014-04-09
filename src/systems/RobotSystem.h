#ifndef ROBOTSYSTEM_H_
#define ROBOTSYSTEM_H_

class Environment;

class RobotSystem {
public:
	virtual void init(Environment*)=0;
};

#endif
