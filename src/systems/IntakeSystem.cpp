#include "IntakeSystem.h"

#include "../RobotMap.h"

IntakeSystem::IntakeSystem() {

}

IntakeSystem::~IntakeSystem() {
	delete motor;
	delete lift;
}

void IntakeSystem::init(Environment* env){
	motor = new Jaguar(INTAKE_MOTOR);
	lift = new Relay(INTAKE_RELAY);
	lift->Set(Relay::kReverse);
}

void IntakeSystem::intake(InputMethod* input){

}

