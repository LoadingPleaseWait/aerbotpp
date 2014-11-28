#ifndef ROBOTSYSTEM_H_
#define ROBOTSYSTEM_H_

#include "../Initializable.h"

class RobotSystem: public Initializable {
public:
	virtual void run() =0;
};

#endif
