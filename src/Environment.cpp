#include "Environment.h"

#include <RobotBase.h>

#include "input/PartnerXboxInput.h"
#include "systems/IntakeSystem.h"
#include "systems/ShooterSystem.h"
#include "systems/WheelSystem.h"
#include "RobotMap.h"

Environment::Environment(RobotBase* bot) {
	robot = bot;

	input = new PartnerXboxInput();

	intake = new IntakeSystem();
	intake->init(this);

	shooter = new ShooterSystem();
	shooter->init(this);

	wheels = new WheelSystem();
	wheels->init(this);

	compressor = new Compressor(COMPRESSOR_PRESSURE, COMPRESSOR_RELAY);
	compressor->Start();
}

Environment::~Environment() {
	delete intake;
	delete input;
	delete shooter;
	delete wheels;
}

bool Environment::isAutonomous(){
	return robot->IsAutonomous();
}

bool Environment::isOperatorControl(){
	return robot->IsOperatorControl();
}

IntakeSystem* Environment::getIntakeSystem(){
	return intake;
}

ShooterSystem* Environment::getShooterSystem(){
	return shooter;
}

WheelSystem* Environment::getWheelSystem(){
	return wheels;
}

InputMethod* Environment::getInput(){
	return input;
}

Compressor* Environment::getCompressor(){
	return compressor;
}

