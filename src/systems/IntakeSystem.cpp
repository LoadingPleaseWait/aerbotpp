#include "IntakeSystem.h"

#include "../input/InputMethod.h"
#include "../RobotMap.h"

IntakeSystem::IntakeSystem() {

}

IntakeSystem::~IntakeSystem() {
	delete motor;
	delete lift;
}

void IntakeSystem::init(Environment* env) {
	motor = new Jaguar(INTAKE_MOTOR);
	lift = new Relay(INTAKE_RELAY);
	lift->Set(Relay::kReverse);
}

void IntakeSystem::intake(InputMethod* input) {
	//auto intake button
	if(input->intakeToggle()){
		setMotor(1);
		open();
		isToggled = true;
	}else if(isToggled && !input->intakeToggle()){
		setMotor(0);
		close();
		isToggled = false;
	}

	//manual control of motors
	if (!isToggled) {
		if (input->intake())
			setMotor(1);
		else if (input->outtake())
			setMotor(-1);
		else
			setMotor(0);
	}

	//catch ball
	if(!catchToggle && input->catchBall()){
		if(lift->Get() == Relay::kForward){
			lift->Set(Relay::kReverse);
		}else{
			lift->Set(Relay::kForward);
		}
	}
	catchToggle = input->catchBall();
}

void IntakeSystem::open() {
	lift->Set(Relay::kForward);
}

void IntakeSystem::close() {
	lift->Set(Relay::kReverse);
}

void IntakeSystem::setMotor(double speed) {
	motor->Set(speed);
}

