/*
 * 
 */

#include "AutonomousListener.h"

#include "../Environment.h"
#include "../systems/IntakeSystem.h"

AutonomousListener::AutonomousListener() {

}

AutonomousListener::~AutonomousListener() {

}

void AutonomousListener::init(Environment* env){
	environment = env;
	started = false;
	timer.Start();
}

bool AutonomousListener::shouldExecute(){
	return environment->isAutonomous();
}

void AutonomousListener::execute(){
	if(!started){
		timer.Reset();
		started = true;
	}
	if(timer.Get() < 2.5){
		//drive forward
	}else if(timer.Get() < 5.5){
		//push forward a bit and outtake
		environment->getIntakeSystem()->setMotor(-1);
	}else{
		//stop motors
		environment->getIntakeSystem()->setMotor(0);
	}
}

