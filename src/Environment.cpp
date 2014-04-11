#include "Environment.h"

Environment::Environment(RobotBase* bot) {
	robot = bot;

	input = new PartnerXboxInput();

	intake = new IntakeSystem();
	intake->init(this);
}

Environment::~Environment() {
	delete intake;
	delete input;
}

bool Environment::isAutonomous(){
	return robot->IsAutonomous();
}

bool Environment::isOperatorControl(){
	return robot->IsOperatorControl();
}

