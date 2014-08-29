#include "WheelSystem.h"


WheelSystem::WheelSystem()
:gear(0), gear_press(false), dir(1), current_left_y(0), current_ramp_y(0)
{

}

WheelSystem::~WheelSystem() {
	delete wheels;
	delete gearbox;
}

void WheelSystem::init(Environment* env){
	wheels = new RobotDrive3(1,2);

	gearbox = new Relay(2);
	this->gearsOff();

	wheels->SetSafetyEnabled(false);

}

void WheelSystem::move(InputMethod* input){
	current_left_y = -input->getLeftY();

	current_ramp_y += (current_left_y - current_ramp_y) * kRamping;

	this->arcadeDrive(current_ramp_y * dir, input->getRightX());

	/*SmartDashboard::putNumber("Gear: ", gear);
	SmartDashboard::putBoolean("Switched Front: ", dir == -1);
	SmartDashboard::putNumber("Ramped Movement: ", current_ramp_y);*/


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
	return this->gear = gear;
}

void WheelSystem::gearsOff(){
	gear = 0;
	gearbox->Set(Relay::kOff);
}

void WheelSystem::gearsReverse(){
	gear = 1;
	gearbox->Set(Relay::kReverse);
}

void WheelSystem::destroy(){

}

/*void WheelSystem::drive(double output_magnitude, double curve){
	wheels->drive(output_magnitude, curve);
}*/

void WheelSystem::arcadeDrive(double move_value, double rotate_value){
	wheels->ArcadeDrive(move_value, rotate_value);
}

double WheelSystem::getCurrentLeftY(){
	return this->current_left_y;
}

void WheelSystem::setCurrentLeftY(double currentLeftY){
	this->current_left_y = currentLeftY;
}
