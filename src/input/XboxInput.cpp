#include "XboxInput.h"

XboxInput::XboxInput() : controller(1) {

}

XboxInput::~XboxInput() {

}

double XboxInput::getLeftX(){
	return controller.GetRawAxis(LEFT_STICK_X);
}

double XboxInput::getLeftY(){
	return controller.GetRawAxis(LEFT_STICK_Y);
}

double XboxInput::getRightX(){
	return controller.GetRawAxis(RIGHT_STICK_X);
}

double XboxInput::getRightY(){
	return controller.GetRawAxis(RIGHT_STICK_Y);
}

bool XboxInput::shift(){
	return controller.GetRawButton(BUTTON_B);
}

bool XboxInput::catchBall(){
	return controller.GetRawButton(BUTTON_START);
}

bool XboxInput::shoot(){
	return controller.GetRawButton(BUTTON_A);
}

bool XboxInput::manualShoot(){
	return controller.GetRawButton(BUTTON_Y);
}

bool XboxInput::intakeToggle(){
	return controller.GetRawButton(BUTTON_X);
}

bool XboxInput::directionToggle(){
	return false;
}

bool XboxInput::intake(){
	return controller.GetRawButton(LEFT_BUMPER);
}

bool XboxInput::outtake(){
	return controller.GetRawButton(RIGHT_BUMPER);
}

