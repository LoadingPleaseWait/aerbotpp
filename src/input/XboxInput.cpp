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
	return controller.GetRawButton(BUTTON_Y);
}

bool XboxInput::shoot(){
	return controller.GetRawButton(LEFT_BUMPER);
}

bool XboxInput::manualShoot(){
	return controller.GetRawButton(LEFT_STICK);
}

bool XboxInput::intakeToggle(){
	return controller.GetRawButton(RIGHT_BUMPER);
}

bool XboxInput::directionToggle(){
	return BUTTON_BACK;
}

bool XboxInput::intake(){
	return controller.GetRawButton(BUTTON_A);
}

bool XboxInput::outtake(){
	return controller.GetRawButton(BUTTON_X);
}
