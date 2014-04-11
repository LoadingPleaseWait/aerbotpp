/*
 * 
 */

#include "ShooterSystem.h"

#include <Relay.h>
#include <Victor.h>

#include "../RobotMap.h"

ShooterSystem::ShooterSystem() {
	// TODO Auto-generated constructor stub

}

ShooterSystem::~ShooterSystem() {
	// TODO Auto-generated destructor stub
}

void ShooterSystem::init(Environment* environment){
	motor = new Victor(SHOOTER_MOTOR);
	pneumatic = new Relay(SHOOTER_RELAY);
	pneumatic->Set(Relay::kOff);
}

