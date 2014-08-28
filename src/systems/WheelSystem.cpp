#include "WheelSystem.h"
#include <SmartDashboard.h>

WheelSystem::WheelSystem() {

}

WheelSystem::~WheelSystem() {
	destroy();
}

void WheelSystem::init(Environment* env){
	// initialize drive train and relay
	wheels = new RobotDrive3(1,2);

	gearbox = new Relay(2);
	this->gearsOff();

	wheels->setSafetyEnabled(false);
}

void WheelSystem::move(InputMethod* input){
	current_left_y = -input->getLeftY();

	current_ramp_y += (current_left_y - current_ramp_y) * kRamping;// ramping Y input

	this->arcadeDrive(current_ramp_y * dir, input->getRightX());

	// put information on the smart dashboard
	SmartDashboard.putNumber("Gear: ", gear);
	SmartDashboard.putBoolean("Switched Front: ", dir == -1);
	SmartDashboard.putNumber("Ramped Movement: ", current_ramp_y);

	// toggle between gears
	bool shift = input->shift();
	if(!shift){
		gear_press = false;
	}

	if(gear_press == false){
		if(shift){
			gear_press = true;
			if(gear == 0){
				this->gearsReverse();
			}else if(gear == 1){
				this->gearsOff();
			}
		}
	}

	// toggle direction
	if(!dir_toggle){
		if(input->directionToggle()){
			dir_toggle = true;
			dir *= -1;
		}
	}
	dir_toggle = input->directionToggle();

}

int WheelSystem::getGear(){
	return this->gear;
}

int WheelSystem::setGear(int gear){
	this->gear = gear;
}

void WheelSystem::gearsOff(){
	gear = 0;
	gearbox->set(Relay.value.kOff);
}

void WheelSystem::gearsReverse(){
	gear = 1;
	gearbox->set(Relay.value.kReverse);
}

void WheelSystem::destroy(){
	// prepare for this object to be destroyed by destroying drive train and relay
	delete wheels;
	delete gearbox;
}

void WheelSystem::drive(double output_magnitude, double curve){
	wheels->drive(output_magnitude, curve);
}

void WheelSystem::arcadeDrive(double move_value, double rotate_value){
	wheels->arcadeDrive(move_value, rotate_value);
}

double WheelSystem::getCurrentLeftY(){
	return this->current_left_y;
}

void WheelSystem::setCurrentLeftY(double currentLeftY){
	this->current_left_y = currentLeftY;
}
