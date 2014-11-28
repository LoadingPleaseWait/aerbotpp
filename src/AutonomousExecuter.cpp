#include "AutonomousExecuter.h"

#include "Environment.h"
#include "systems/IntakeSystem.h"
#include "systems/WheelSystem.h"

AutonomousExecuter::AutonomousExecuter() {

}

AutonomousExecuter::AutonomousExecuter(Environment* env) {
	init(env);
}

AutonomousExecuter::~AutonomousExecuter() {

}

void AutonomousExecuter::init(Environment* env){
	environment = env;
	started = false;
	timer.Start();
}

void AutonomousExecuter::execute(){
	if(!started){
		timer.Reset();
		started = true;
	}
	if(timer.Get() < 2.5){
		//drive forward
		environment->getWheelSystem()->arcadeDrive(-1,0);
	}else if(timer.Get() < 5.5){
		//push forward a bit and outtake
		environment->getWheelSystem()->arcadeDrive(.4,0);
		environment->getIntakeSystem()->setMotor(-1);
	}else{
		environment->getWheelSystem()->arcadeDrive(0,0);//stop motors
		environment->getIntakeSystem()->setMotor(0);
	}
}

