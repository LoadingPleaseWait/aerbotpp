/*
 * 
 */

#include "ShooterSystem.h"

#include <Relay.h>
#include <Victor.h>

#include "../input/InputMethod.h"
#include "../RobotMap.h"

ShooterSystem::ShooterSystem() {

}

ShooterSystem::~ShooterSystem() {
	delete pneumatic;
	delete motor;
}

void ShooterSystem::init(Environment* environment){
	motor = new Victor(SHOOTER_MOTOR);
	pneumatic = new Relay(SHOOTER_RELAY);
	pneumatic->Set(Relay::kOff);
}

void ShooterSystem::shoot(InputMethod* input){
	if(!isToggled && input->shoot()){
		if(!shooting){

		}
	}
}

void ShooterSystem::open(){
	pneumatic->Set(Relay::kForward);
}

void ShooterSystem::close(){
	pneumatic->Set(Relay::kOff);
}

void ShooterSystem::setMotor(double speed){
	motor->Set(speed);
}

