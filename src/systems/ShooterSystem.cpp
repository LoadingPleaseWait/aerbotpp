#include "ShooterSystem.h"

#include <Relay.h>
#include <Victor.h>
#include <SpeedController.h>

#include "../input/InputMethod.h"
#include "../RobotMap.h"


ShooterSystem::ShooterSystem() {

}

ShooterSystem::~ShooterSystem() {
	delete pneumatic;
	delete motor;
}

void ShooterSystem::init(Environment* environment){
	// initialize motor and relay
	Victor** motors;
	motors[0] = new Victor(SHOOTER_MOTOR_1);
	motors[1] = new Victor(SHOOTER_MOTOR_2);
	pneumatic = new Solenoid(SHOOTER_RELAY);
	timer.Start();
	inputMethod = environment->getInput();
}

void ShooterSystem::run(){
	shoot(inputMethod);
}

void ShooterSystem::shoot(InputMethod* input){
	//toggle auto shoot
	if(!isToggled && input->shoot()){
		if(!shooting){
			timer.Reset();
			setMotor(1);
		}else
			setMotor(0);
		close();
		shooting = !shooting;
	}

	//auto shoot
	if(shooting){
		if(timer.Get() >= 4 && timer.Get() < 4.5)
			open();
		else{
			shooting = false;
			close();
			setMotor(0);
		}
	}else if(!shootPressed && input->manualShoot()){
		//manual toggle shooting
		if(manualShooting){
			close();
			setMotor(0);
		}else{
			open();
			setMotor(1);
		}
		manualShooting = !manualShooting;
	}
	shootPressed = input->manualShoot();

	//catch and open after catch
	if(!catchToggle && input->catchBall()){
		if(!pneumatic->Get()){
			setMotor(0);
			close();
		}else{
			setMotor(-.25);
			open();
		}
	}
	catchToggle = input->catchBall();
}

void ShooterSystem::open(){
	pneumatic->Set(true);
}

void ShooterSystem::close(){
	pneumatic->Set(false);
}

void ShooterSystem::setMotor(double speed){
	motor->Set(speed);
}
